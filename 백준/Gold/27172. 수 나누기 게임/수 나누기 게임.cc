#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> sequence;
int point[1000001];
bool appearance[1000001];

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	sequence.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
		appearance[sequence[i]] = true;
	}

	for (auto& it : sequence) {
		for (int j = it * 2; j <= 1000000; j += it) {
			if (appearance[j]) {
				point[j]--;
				point[it]++;
			}
		}
	}
	for (auto& it : sequence)
		cout << point[it] << ' ';
}