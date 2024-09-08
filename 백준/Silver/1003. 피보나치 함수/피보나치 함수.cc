#include <bits/stdc++.h>
using namespace std;

int count1[41];
int count0[41];

int main(void)
{
	int t, n;
	cin >> t;

	count0[0] = 1;
	count1[1] = 1;

	for (int i = 2; i < 41; i++) {
		count1[i] = count1[i - 1] + count1[i - 2];
		count0[i] = count0[i - 1] + count0[i - 2];
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << count0[n] << " " << count1[n] << "\n";
	}
}