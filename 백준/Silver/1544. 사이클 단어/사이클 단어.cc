#include <bits/stdc++.h>
using namespace std;

int N, res;
string s;
set<string> words;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (words.contains(s))
			continue;
		res++;

		for (int j = 0; j < s.size(); j++) {
			words.insert(s);
			s = s.substr(1) + s[0];
		}
	}
	cout << res;
}