#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M, d, s;
int board[50][100];
bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

vector<point> clouds;
bool removed[50][50];

void moveCloud(int d, int s) {
	memset(removed, 0, sizeof(removed));

	// step 1
	for (auto& it : clouds) {
		int ny = (it.y + dy[d] * s + N * 50) % N;
		int nx = (it.x + dx[d] * s + N * 50) % N;
		
		it = { ny, nx };
	}

	// step 2
	for (auto& it : clouds) {
		board[it.y][it.x]++;
	}

	// step 3
	for (auto& it : clouds) {
		removed[it.y][it.x] = true;
	}


	// step 4
	for (auto& it : clouds) {
		int cnt = 0;
		for (int i = 1; i < 8; i += 2) {
			int ny = it.y + dy[i];
			int nx = it.x + dx[i];
			if (is_in_range(ny, nx) && board[ny][nx] > 0)
				cnt++;
		}
		board[it.y][it.x] += cnt;
	}

	// step 5
	clouds.clear();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (board[i][j] >= 2 && !removed[i][j]) {
				clouds.push_back({ i, j });
				board[i][j] -= 2;
			}
		}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	clouds.push_back({ N - 1, 0 });
	clouds.push_back({ N - 1, 1 });
	clouds.push_back({ N - 2, 0 });
	clouds.push_back({ N - 2, 1 });
	
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		moveCloud(d - 1, s);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum += board[i][j];
	cout << sum;
}