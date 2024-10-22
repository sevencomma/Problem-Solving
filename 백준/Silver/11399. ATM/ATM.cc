#include <bits/stdc++.h>
using namespace std;

int n, sum;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	b[0] = a[0];
	for (int i = 1; i < n; i++)
		b[i] = b[i - 1] + a[i];
	for (int i = 0; i < n; i++)
		sum += b[i];
	cout << sum;
}