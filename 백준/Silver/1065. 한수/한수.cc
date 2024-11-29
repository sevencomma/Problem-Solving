#include <bits/stdc++.h>
using namespace std;
int cnt, n;
int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		bool check = true;

		for (int j = 2; j < s.length(); j++)
			if (s[j] - s[j - 1] != s[j - 1] - s[j - 2])
				check = false;
		if (check)
			cnt++;
	} cout << cnt;
}