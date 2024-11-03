#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int a[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < i; j++) {
			if (a[i] + a[j] + 100 == sum) {
				for (int s = 0; s < 9; s++) {
					if (s == i || s == j)
						continue;
					cout << a[s] << '\n';
				}
				break;
			}
		}
}