#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> boards;

bool can_put(int x, int y) {
	for (int i = 0; i < x; i++) {
		if (boards[i] == y)
			return false;
		if (abs(x - i) == abs(y - boards[i]))
			return false;
	}
	return true;
}

int back_tracking(int col) {
	if (col == N)
		return 1;

	int count = 0;
	for (int row = 0; row < N; row++) {
		if (can_put(col, row)) {
			boards[col] = row;
			count += back_tracking(col + 1);
			boards[col] = -1;
		}
	}
	return count;
}

int main(void) {
	cin >> N;
	boards.resize(N, -1);
	cout << back_tracking(0);
}