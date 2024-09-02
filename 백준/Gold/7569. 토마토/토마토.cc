#include <bits/stdc++.h>
using namespace std;

struct point {
	int z, y, x, cnt;
};

int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 0, 1, 0 };
int dx[6] = { 0, 0, 0, 1, 0, -1 };

int h, n, m;
int box[100][100][100];	// z-y-x
bool visited[100][100][100] = { false };

bool is_in_range(int z, int y, int x) {
	return (z >= 0 && z < h && y >= 0 && y < n && x >= 0 && x < m);
}

int bfs(vector<point>& tomato) {
	queue<point> q;
	for (auto& it : tomato) {
		q.push({ it.z, it.y, it.x, it.cnt });
		visited[it.z][it.y][it.x] = true;
	}

	int count;
	while (!q.empty()) {
		point temp = q.front();
		q.pop();
		count = temp.cnt;

		for (int i = 0; i < 6; i++) {
			int cz = temp.z + dz[i];
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];

			if (!is_in_range(cz, cy, cx) || visited[cz][cy][cx] || box[cz][cy][cx] != 0)
				continue;

			q.push({ cz, cy, cx, temp.cnt + 1 });
			visited[cz][cy][cx] = true;
			box[cz][cy][cx] = 1;
		}
	}
	return count;
}


int main(void)
{
	cin >> m >> n >> h;
	vector<point> tomato;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
					tomato.push_back({ i, j, k, 0 });
			}

	int res = bfs(tomato);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
	cout << res;
}