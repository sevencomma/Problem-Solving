#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> part;
int T, N, M;

int who[1001];
bool visited[1001];

int dfs(int n) {
	for (int i = part[n].first; i <= part[n].second; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		if (who[i] == -1 || dfs(who[i])) {
			who[i] = n;
			return true;
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		part.clear();
		part.resize(M);
		memset(who, -1, sizeof(who));
		for (int i = 0; i < M; i++)
			cin >> part[i].first >> part[i].second;

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i))
				cnt++;
		}
		cout << cnt << "\n";
	}
}