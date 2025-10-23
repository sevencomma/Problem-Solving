#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int R, C, T;
int board[50][50];
int tempBoard[50][50];
vector<pair<int, int>> pathUp;
vector<pair<int, int>> pathDown;

bool is_in_range(int y, int x) {
	return (y >= 0 && y < R && x >= 0 && x < C);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				if (pathUp.empty())
					pathUp.push_back({ i, j });
				else
					pathDown.push_back({ i, j });
			}
		}

	int dir = 0;
	while (1) {
		int ny = pathUp.back().first + dy[dir];
		int nx = pathUp.back().second + dx[dir];
		if (!is_in_range(ny, nx) || ny > pathUp[0].first) {
			dir = (dir + 1) % 4;
			continue;
		}
		pathUp.push_back({ ny, nx });
		if (ny == pathUp[0].first && nx == pathUp[0].second)
			break;
	}
	dir = 0;
	while (1) {
		int ny = pathDown.back().first + dy[dir];
		int nx = pathDown.back().second + dx[dir];
		if (!is_in_range(ny, nx) || ny < pathDown[0].first) {
			dir = (dir + 3) % 4;
			continue;
		}
		pathDown.push_back({ ny, nx });
		if (ny == pathDown[0].first && nx == pathDown[0].second)
			break;
	}

	while (T--) {
		memset(tempBoard, 0, sizeof(tempBoard));

		// 미세먼지 확산
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (board[i][j] == 0 || board[i][j] == -1)
					continue;

				int spreadAmount = board[i][j] / 5;
				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (!is_in_range(ny, nx) || board[ny][nx] == -1)
						continue;
					tempBoard[ny][nx] += spreadAmount;
					board[i][j] -= spreadAmount;
				}
			}

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				board[i][j] += tempBoard[i][j];

		// 공기청정기 작동
		for (int i = pathUp.size() - 2; i > 0; i--) {
			if (board[pathUp[i + 1].first][pathUp[i + 1].second] != -1)
				board[pathUp[i + 1].first][pathUp[i + 1].second] = board[pathUp[i].first][pathUp[i].second];
			board[pathUp[i].first][pathUp[i].second] = 0;
		}
		for (int i = pathDown.size() - 2; i > 0; i--) {
			if (board[pathDown[i + 1].first][pathDown[i + 1].second] != -1)
				board[pathDown[i + 1].first][pathDown[i + 1].second] = board[pathDown[i].first][pathDown[i].second];
			board[pathDown[i].first][pathDown[i].second] = 0;
		}
	}

	int amount = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (board[i][j] > 0)
				amount += board[i][j];
	cout << amount;
}