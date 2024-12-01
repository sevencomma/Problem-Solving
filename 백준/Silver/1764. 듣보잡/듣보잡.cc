#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dbz;
vector<string> dbz_list;
int N, M;
string s;
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin.ignore();
	for (int i = 0; i < N + M; i++) {
		getline(cin, s);
		dbz[s]++;
	}
	for (auto& it : dbz)
		if (it.second == 2)
			dbz_list.push_back(it.first);
	sort(dbz_list.begin(), dbz_list.end());
	cout << dbz_list.size() << '\n';
	for (auto& it : dbz_list)
		cout << it << '\n';
}