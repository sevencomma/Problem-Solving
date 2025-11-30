#include <bits/stdc++.h>
using namespace std;

int N, M, x, res;
unordered_map<int, int> dict;
vector<int> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		dict[x]++;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	for (auto& it : arr) {
		if (dict.find(it) == dict.end())
			continue;

		if (dict.find(M - it) != dict.end() ) {

			if (it == M - it) {
				if (dict[it] < 2) continue;
			}
			res++;
			dict[M - it]--;
			if (dict[M - it] == 0)
				dict.erase(M - it);

			dict[it]--;
			if (dict[it] == 0)
				dict.erase(it);
		}
	}
	cout << res;
}