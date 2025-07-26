#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<char, int> cnt;

int main(void) {
	char c;

	while (1) {
		cin >> c;
		if (cin.eof()) break;
		cnt[c]++;
	}
	vector<char> x;
	auto maxIter = max_element(cnt.begin(), cnt.end(),
		[](const auto& a, const auto& b) {
			return a.second < b.second;
		});

	for (auto& it : cnt) {
		if (it.second == maxIter->second)
			x.push_back(it.first);
	}

	sort(x.begin(), x.end());
	for (auto& c : x)
		cout << c;
}
