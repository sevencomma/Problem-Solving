#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int pos, cnt;
};

int N, K, M;
int F = 1;
unordered_map<int, vector<int>> linker;
unordered_map<int, vector<int>> layer;
vector<int> input_data;
bool visited[100001];

int bfs()	{
	queue<point> q;
	q.push({ 1, 1 });
	visited[1] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		//cout << "::: " << cur.pos << ", " << cur.cnt << endl;
		if (cur.pos == N)
			return cur.cnt;

		for (auto& it : layer[cur.pos]) {
			for (auto& go : linker[it]) {
				if (!visited[go]) {
					q.push({ go, cur.cnt + 1 });
					visited[go] = true;
				}
			}
		}
	
	}
	return -1;
}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K >> M;
	input_data.resize(K);
	for (int i = 0; i < M; i++) {
		F++;
		for (int j = 0; j < K; j++) {
			cin >> input_data[j];
			layer[input_data[j]].push_back(F);
		}
		for (int j = 0; j < K; j++)
			linker[F].push_back(input_data[j]);
	}

	cout << bfs();
}