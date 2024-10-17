#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	char a, b;
	while (1) {
		cin >> a >> b;
		if (cin.eof())
			break;
		cout << a - '0' + b - '0' << '\n';
	}
}