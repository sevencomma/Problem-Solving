#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	stack<char> s;
	int N = str.length();

	for (int i = 0; i < N; i++) {
		if (str[i] == 'P')
			s.push(str[i]);
		else {
			if (s.size() < 2 || str[i + 1] != 'P') {
				cout << "NP";
				return 0;
			}
			else {
				s.pop();
				i++;
			}
		}
	}
	if (s.size() != 1) {
		cout << "NP";
		return 0;
	}
	cout << "PPAP";
}