#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator() (const string& a, const string& b) const {
		if (a.size() == b.size())
			return a < b;
		return a.size() < b.size();
	}
};

int main(void)
{
	int n, result = 0;
	cin >> n;
	cin.ignore();

	set<string, compare> sentence;
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);

		sentence.insert(temp);
	}

	for (auto& it : sentence)
		cout << it << "\n";
}