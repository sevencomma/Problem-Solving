#include <bits/stdc++.h>
using namespace std;

int N, sum;
int stick[40];
int cache[40][801][801];

int dp(int idx, int a, int b) {
    int c = sum - a - b;
    if (a * 2 >= sum || b * 2 >= sum)
        return 0;

    if (idx == N) {
        if (a >= b + c || b >= a + c || c >= a + b)
            return 0;
        double s = (a + b + c) / 2.0;
		double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return (int)(area * 100);
	}

    int& ret = cache[idx][a][b];
    if (ret != -1) return ret;
    ret = 0;

	ret = max(ret, dp(idx + 1, a + stick[idx], b));
    ret = max(ret, dp(idx + 1, a, b + stick[idx]));
    ret = max(ret, dp(idx + 1, a, b));

    return ret;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> stick[i];
    for (int i = 0; i < N; i++)
		sum += stick[i];
    memset(cache, -1, sizeof(cache));
    dp(0, 0, 0);
    if (cache[0][0][0] == 0) cout << -1;
	else cout << cache[0][0][0];
}
