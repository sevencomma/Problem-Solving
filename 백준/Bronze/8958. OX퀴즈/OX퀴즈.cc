#include <bits/stdc++.h>
using namespace std;

int t, cnt[81];
string sen;

int main(void) {
	cin >> t; cin.ignore();
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		getline(cin, sen);
		int n = 0, res = 0;
		for (int i = 0; i < sen.size(); i++) {
			if (sen[i] == 'O')
				cnt[i] = ++n;
			else
				n = 0;
		}
		for (int i = 0; i < sen.size(); i++)
			res += cnt[i];
		cout << res << "\n";
	}
}