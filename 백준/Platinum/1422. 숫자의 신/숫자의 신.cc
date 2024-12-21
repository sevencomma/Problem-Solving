#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	return a + b > b + a;
}

int K, N;
vector<string> seq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> K >> N;
	cin.ignore();
	seq.resize(K);
	for (int i = 0; i < K; i++)
		getline(cin, seq[i]);

	if (N > K) {
		int max_len = 0;
		string temp = "";
		for (auto& it : seq)
			max_len = max(max_len, (int)it.length());
		for (auto& it : seq) {
			if ((int)it.length() == max_len && it > temp)
				temp = it;
		}
		for (int i = 0; i < N - K; i++)
			seq.push_back(temp);
	}
	sort(seq.begin(), seq.end(), compare);
	for (auto& it : seq)
		cout << it;
}