#include <bits/stdc++.h>
using namespace std;
vector<int> a(3);
int main(void) {
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[1];
}