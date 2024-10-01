#include <bits/stdc++.h>
using namespace std;

int N, S, pos;
vector<int> sequence;

int find_max(int pos, int s) {
	int p = pos;
	int max_num = sequence[pos];
	for (int i = pos; i <= pos + s; i++) {
		if (i >= N)
			break;
		
		if (max_num < sequence[i]) {
			max_num = sequence[i];
			p = i;
		}
	}
	return p;
}

int main(void) {
	cin >> N;
	sequence.resize(N);
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	cin >> S;

	while (pos < N && S > 0) {
		int k = find_max(pos, S);
		if (k == pos) {
			pos++;
			continue;
		}
		int temp = sequence[k];
		auto it = sequence.begin();
		it += k;
		sequence.erase(it);
		it = sequence.begin() + pos;
		sequence.insert(it, temp);
		S -= (k - pos);
		pos++;
	}

	for (auto& it : sequence)
		cout << it << ' ';
}