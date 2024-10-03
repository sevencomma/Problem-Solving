#include <bits/stdc++.h>
using namespace std;

char board[9][9];

bool is_safe(int y, int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[y][i] - '0' == num)
			return false;
		if (board[i][x] - '0' == num)
			return false;
	}
	int a = y / 3, b = x / 3;
	for (int i = a * 3; i < a * 3 + 3; i++)
		for (int j = b * 3; j < b * 3 + 3; j++)
			if (board[i][j] - '0' == num)
				return false;
	return true;
}

pair<int, int> find_empty() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (board[i][j] == '0')
				return { i, j };
	return { -1, -1 };
}
 
void back_tracking(pair<int, int> pos) {
	for (int num = 1; num <= 9; num++) {
		if (is_safe(pos.first, pos.second, num)) {
			board[pos.first][pos.second] = num - 0 + '0';
			
			pair<int, int> next = find_empty();

			if (next.first == -1) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++)
						cout << board[i][j];
					cout << '\n';
				}
				exit(EXIT_SUCCESS);
			}

			back_tracking(next);
			board[pos.first][pos.second] = '0';
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];

	pair<int, int> pos = find_empty();
	if (pos.first != -1)
		back_tracking(pos);
	else {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << '\n';
		}
	}
}