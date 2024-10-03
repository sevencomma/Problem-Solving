#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int len[1001][1001];
int move_print[1001][1001];

void LCS_len(int m, int n) {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (s1[i-1] == s2[j-1]) {
				len[i][j] = len[i - 1][j - 1] + 1;
				move_print[i][j] = 1;
			}
			else if (len[i - 1][j] >= len[i][j - 1]) {
				len[i][j] = len[i - 1][j];
				move_print[i][j] = 2;
			}
			else {
				len[i][j] = len[i][j - 1];
				move_print[i][j] = 3;
			}
		}
}

void print_LCS(int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (move_print[i][j] == 1) {
		print_LCS(i - 1, j - 1);
		cout << s1[i-1];
	}
	else if (move_print[i][j] == 2)
		print_LCS(i - 1, j);
	else
		print_LCS(i, j - 1);
}

int main(void) {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	getline(cin, s1);
	getline(cin, s2);

	LCS_len(s1.length(), s2.length());

	cout << len[s1.length()][s2.length()] << '\n';
	print_LCS(s1.length(), s2.length());
}