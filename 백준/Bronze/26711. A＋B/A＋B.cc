#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<char> c(max(a.size(), b.size()) + 1, '0');

	for (int i = 0; i < c.size() - 1; i++) {
		if (i < a.size())
			c[i] += a[i] - '0';
		if (i < b.size())
			c[i] += b[i] - '0';

		while (c[i] > '9') {
			c[i] -= 10;
			c[i + 1]++;
		}
	}

	int lastIdx = c.size() - 1;
	if (c.back() == '0') lastIdx--;

	for (int i = lastIdx; i >= 0; i--)
		cout << c[i];
}