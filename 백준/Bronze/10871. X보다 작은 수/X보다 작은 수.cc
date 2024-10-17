#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m, tmp;
	cin >> n >> m;
	while (n--) {
		cin >> tmp;
		if (tmp < m)
			cout << tmp << ' ';
	}
}