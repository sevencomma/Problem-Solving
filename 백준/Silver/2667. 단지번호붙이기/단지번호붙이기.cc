#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct point {
	int y, x;
};

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n;

bool visited[25][25];

bool is_in_bound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

int bfs(int y, int x, vector<string> &chart) {
	if (visited[y][x])
		return 0;

	if (chart[y][x] == '0') {
		visited[y][x] = true;
		return 0;
	}

	queue<point> q;
	q.push({ y, x});
	visited[y][x] = true;

	int count = 1;
	while (!q.empty()) {
		point temp = q.front();
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];

			if (is_in_bound(ny, nx) && !visited[ny][nx] && chart[ny][nx] == '1') {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();

	n = N;
	vector<string> chart(N);

	for (int i = 0; i < N; i++) {
		getline(cin, chart[i]);
	}

	vector<int> answer;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = bfs(i, j, chart);
			if (num != 0) {
				answer.push_back(num);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (auto& it : answer)
		cout << it << "\n";
}