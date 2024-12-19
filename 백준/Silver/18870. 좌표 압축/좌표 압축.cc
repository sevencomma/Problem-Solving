#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int N;
vector<int> seq;
unordered_set<int> num;
unordered_map<int, int> cnt;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	seq.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		num.insert(seq[i]);
	}
	vector<int> temp;
	for (auto& it : num)
		temp.push_back(it);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++)
		cnt[temp[i]] = i;

	for (auto& it : seq)
		cout << cnt[it] << ' ';
}