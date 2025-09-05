#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> crane;
int startIdx[51];
vector<int> box;
bool visited[10001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	crane.resize(N);
	for (int i = 0; i < N; i++)
		cin >> crane[i];
	cin >> M;
	box.resize(M);
	for (int i = 0; i < M; i++)
		cin >> box[i];
	sort(crane.rbegin(), crane.rend());
	sort(box.rbegin(), box.rend());

	if (crane[0] < box[0]) {
		cout << -1;
		return 0;
	}
	int cnt = 0, idx = 0;
	for (int i = 0; i < N; i++) {
		while (idx < M && crane[i] < box[idx])
			idx++;
		startIdx[i] = idx;
	}

	while (startIdx[0] < M) {
		cnt++;
		for (int i = 0; i < N; i++) {
			if (startIdx[i] == M) continue;
			while (startIdx[i] < M && visited[startIdx[i]])
				startIdx[i]++;
			visited[startIdx[i]] = true;
		}
	}

	cout << cnt - 1;
}