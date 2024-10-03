#include <bits/stdc++.h>
using namespace std;

int N;
int direct[100001];
bool visited[100001];
bool re[100001];
int sum;
void dfs(int start) {
	if (re[start]) return;
	if (visited[start]) {
		re[start] = true;
		sum++;
	}
	visited[start] = true;
	dfs(direct[start]);
	re[start] = true;
	visited[start] = false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(direct, 0, sizeof(direct));
		memset(visited, false, sizeof(visited));
		memset(re, false, sizeof(re));
		sum = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> direct[i];

		for (int i = 1; i <= N; i++)
			if (!re[i])
				dfs(i);
		cout << N - sum << endl;
	}
}