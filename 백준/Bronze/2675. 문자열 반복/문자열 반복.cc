#include <bits/stdc++.h>
using namespace std;

int T, n;
string sen;

int main(void) {
	cin >> T;
	while (T--) {
		cin >> n;
		cin.ignore();
		getline(cin, sen);
		for (auto& it : sen) {
			for (int i = 0; i < n; i++)
				cout << it;
		}
		cout << "\n";
	}
}