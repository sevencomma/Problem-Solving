#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<vector<int>> graph(n + 1);
	vector<int> edges_cnt(n + 1, 0);
	vector<int> edges_cnt_save(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		edges_cnt[a]++;
		edges_cnt[b]++;
		edges_cnt_save[a]++;
		edges_cnt_save[b]++;
	}
	vector<int> roads(n);
	for (int i = 0; i < n; i++)
		cin >> roads[i];

	if (roads[0] != 1) {
		cout << 0;
		return 0;
	}
	int s = 0;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (auto& it : graph[roads[s]]) {
			if (it == roads[i + 1]) {
				cnt++;
				edges_cnt[it]--;
				edges_cnt[roads[s]]--;
				break;
			}
		}
		while (s < n - 1 && cnt == edges_cnt_save[roads[s]]) {
			s++;
			cnt = edges_cnt_save[roads[s]] - edges_cnt[roads[s]];
		}
	}
	for (int i = 1; i <= n; i++)
		if (edges_cnt[i] != 0) {
			cout << 0;
			return 0;
		}
	cout << 1;
}