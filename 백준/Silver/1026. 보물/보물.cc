#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, result = 0;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	for (int i = 0; i < n; i++)
		result += a[i] * b[i];
	cout << result;
}