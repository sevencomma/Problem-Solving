#include <bits/stdc++.h>
#include <bit>
using namespace std;

#define MAX_SIZE 5000000
#define MAX_PRIME 5000003
#define INF 123456789

int T, N, M;
vector<int> arr;
bool is_prime[MAX_SIZE + 1];
int dist[MAX_SIZE + 1];

int cache[16][1 << 15];

void calculateDistance() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX_SIZE; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_SIZE; j += i)
                is_prime[j] = false;
        }
    }

    // 이전 소수까지의 거리 계산
    int last_prime = -1;

    for (int i = 1; i <= MAX_SIZE; i++) {
        if (is_prime[i]) {
            if (last_prime != -1) {
                dist[i] = i - last_prime;
            }
            else {
                dist[i] = MAX_SIZE;
            }
            last_prime = i;
        }
        else {
            if (last_prime != -1) {
                dist[i] = i - last_prime;
            }
            else {
                dist[i] = MAX_SIZE;
            }
        }
    }

    // 다음 소수까지의 거리 계산 및 최소값 갱신
    int next_prime = MAX_PRIME;

    for (int i = MAX_SIZE; i >= 1; i--) {
        int dist_next = next_prime - i;

        if (is_prime[i]) {
            dist[i] = min(dist[i], dist_next);
            next_prime = i;
        }
        else {
            dist[i] = min(dist[i], dist_next);
        }
    }
}

int calculate_mask_sum(int mask) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        if (mask & (1 << i))
            sum += arr[i];
    return sum;
}

int dp(int user, int cardMask) {
    if (cardMask == 0)
        return (user == 0) ? 0 : INF;
    if (user == 0 || popcount((unsigned int)cardMask) < user) return INF;

    int& ret = cache[user][cardMask];
    if (ret != -1) return ret;
    ret = INF;

    int first_card_idx = countr_zero((unsigned int)cardMask); // card_mask에서 가장 낮은 비트의 인덱스

    // submask는 card_mask의 공집합이 아닌 부분 집합이어야 함
    // (submask는 first_card_idx를 포함해야 중복되지 않음)
    for (int submask = cardMask; submask > 0; submask = (submask - 1) & cardMask) {

        if (!(submask & (1 << first_card_idx))) continue;

        int current_sum = calculate_mask_sum(submask);
        int current_score = dist[current_sum];

        // 나머지 카드 (mask \ submask)를 user-1명에게 분배한 결과
        int remaining_mask = cardMask ^ submask; // mask \ submask
        int remaining_max_score = dp(user - 1, remaining_mask);

        int max_score = max(current_score, remaining_max_score);

        ret = min(ret, max_score);
    }

    return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	calculateDistance();

	while (T--) {
		cin >> N >> M;
		arr.resize(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
        memset(cache, -1, sizeof(cache));

        int final_mask = (1 << N) - 1;
		cout << dp(M, final_mask) << '\n';
		arr.clear();
	}
}