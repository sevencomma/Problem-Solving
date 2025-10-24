#include <bits/stdc++.h>
using namespace std;

int resTime = INT_MAX, resHeight = -1;

int N, M, B;
int board[500][500];

void getSolve(int targetHeight) {
	int time = 0;
	int block = B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (board[i][j] < targetHeight) {
				int diff = targetHeight - board[i][j];
				time += diff;
				block -= diff;
			}
			else if (board[i][j] > targetHeight) {
				int diff = board[i][j] - targetHeight;
				time += diff * 2;
				block += diff;
			}
		}

	if (block < 0)
		return;

	if (resTime >= time) {
		resTime = time;
		resHeight = max(resHeight, targetHeight);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> B;
	int minH = INT_MAX, maxH = INT_MIN;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			minH = min(minH, board[i][j]);
			maxH = max(maxH, board[i][j]);
		}

	for (int h = minH; h <= maxH; h++)
		getSolve(h);
	cout << resTime << " " << resHeight << "\n";
}