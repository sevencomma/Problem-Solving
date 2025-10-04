#include <bits/stdc++.h>
using namespace std;

int N, c;
double M, p;
vector<pair<int, int>> candies;
int cache[10001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		M = (int)(M * 100 + 0.5);
		if (N == 0 && M == 0) break;
		candies.clear();
		memset(cache, 0, sizeof(cache));
		for (int i = 0; i < N; i++) {
			cin >> c >> p;
			candies.push_back({ c, (int)(p * 100 + 0.5) });
		}
		
		for (int i = 0; i < N; i++)
			for (int j = candies[i].second; j <= M; j++)
				cache[j] = max(cache[j], cache[j - candies[i].second] + candies[i].first);
		cout << cache[(int)M] << '\n';
	}
}