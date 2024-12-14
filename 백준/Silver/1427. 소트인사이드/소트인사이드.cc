#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	vector<int> num;
	for (auto& it : s)
		num.push_back(it - '0');
	sort(num.rbegin(), num.rend());
	for (auto& it : num)
		cout << it;
}