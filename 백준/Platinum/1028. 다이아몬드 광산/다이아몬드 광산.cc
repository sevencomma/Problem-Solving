#include <bits/stdc++.h>
using namespace std;

int R, C, res;
char board[750][750];

// [i][j][4] : (i,j)위치 기준으로 {왼쪽 위, 오른쪽 위} 대각선에 연속해서 몇개가 있는지
int cache[750][750][2];

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

// cache[i][j][1] : size 일때 검증
// 마름모 모양의 가장 왼쪽 좌표로, size값이 들어올때, 해당 모양의 다이아가 가능한지.
bool isEnable(int i, int j, int size) {
	if (cache[i][j][1] < size)
		return false;

	int ry, rx;	// 마름오의 우측 꼭짓점 좌표
	int by, bx; // 마름모의 하단 꼭짓점 좌표

	by = i + size - 1;
	bx = j + size - 1;

	ry = i;
	rx = bx + size - 1;

	if (is_in_range(by, bx) && is_in_range(ry, rx)) {
		if (cache[ry][rx][0] >= size &&
				cache[by][bx][0] >= size &&
				cache[by][bx][1] >= size)
			return true;
	}

	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '0')
				continue;
			cache[i][j][0]++;
			cache[i][j][1]++;

			if (is_in_range(i - 1, j - 1))
				cache[i][j][0] += cache[i - 1][j - 1][0];
			if (is_in_range(i - 1, j + 1))
				cache[i][j][1] += cache[i - 1][j + 1][1];
		}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (cache[i][j][1] > res) {
				int s = cache[i][j][1];
				while (s > res) {
					if (isEnable(i, j, s)) {
						res = max(res, s);
						break;
					}
					s--;
				}
			}
		}
	cout << res;
}