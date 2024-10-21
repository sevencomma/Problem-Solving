#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int x; cin >> x;
	double m = 0;
	vector<double> num(x);
	for (int i = 0; i < x; i++) {
		cin >> num[i];
		if (m < num[i])
			m = num[i];
	}
	for (int i = 0; i < x; i++)
		num[i] = num[i] / m * 100;
	double res = 0;
	for (int i = 0; i < x; i++)
		res += num[i];
	cout << res / x;
}