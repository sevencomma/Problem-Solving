#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	int k = max(n, m) + 1;
	vector<int> c(k);

	for (int i = 0; i < n; i++)
		c[i] = a[n - 1 - i] - '0';
	for (int j = 0; j < m; j++)
		c[j] += b[m - 1 - j] - '0';
	for (int s = 0; s < c.size(); s++)
		if (c[s] >= 10)
			c[s + 1]++, c[s] -= 10;
	if (c[k - 1] != 0)
		cout << c[k - 1];
	for (int i = k - 2; i >= 0; i--)
		cout << c[i];
}