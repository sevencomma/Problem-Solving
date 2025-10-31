#include <bits/stdc++.h>
using namespace std;

int N;
string s, temp;

void push(int idx) {
	for (int i = idx; i <= idx + 2; i++) {
		if (temp[i] == 'R') temp[i] = 'G';
		else if (temp[i] == 'G') temp[i] = 'B';
		else if (temp[i] == 'B') temp[i] = 'R';
	}
}

int getCount(char target) {
	temp = s;
	int count = 0;

	for (int i = 0; i < N - 2; i++) {
		while (temp[i] != target) {
			push(i);
			count++;
		}
	}
	
	if (temp[N - 2] != target || temp[N - 1] != target) return INT_MAX;
	return count;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> s;
	int res = INT_MAX;
	res = min(res, getCount('R'));
	res = min(res, getCount('G'));
	res = min(res, getCount('B'));
	
	if (res == INT_MAX) cout << -1;
	else cout << res;
}