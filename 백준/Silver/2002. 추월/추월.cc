#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, res;
string s;
vector<int> out;
bool visited[1001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;

	unordered_map<string, int> dict;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		dict[s] = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> s;
		out.push_back(dict[s]);
	}

	int target = 1;
	for (auto& it : out) {
		visited[it] = true;
		if (it != target) {
			res++;
		}
		else {
			while (visited[target])
				target++;
		}
	}
	cout << res;
}