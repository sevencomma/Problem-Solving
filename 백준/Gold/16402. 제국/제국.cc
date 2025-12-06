#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
unordered_map<string, int> dict;
vector<string> orig;

vector<string> parsing(string& input, string delimeter) {
	vector<string> res;
	int pos = 0;
	string token;

	while ((pos = input.find(delimeter)) != string::npos) {
		token = input.substr(0, pos);
		input = input.substr(pos + 1);
		res.push_back(token);
	}
	res.push_back(input);
	return res;
}

int Parent[501];

int Find(int x) {
	if (Parent[x] != x)
		Parent[x] = Find(Parent[x]);
	return Parent[x];
}

// y의 parent를 x로 유니온
void Union(int x, int y) {
	int a = Find(x);
	int b = Find(y);

	Parent[b] = a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin.ignore();
	orig.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		getline(cin, s);
		dict[s] = i;
		Parent[i] = i;
		orig[i] = s;
	}

	for (int i = 0; i < M; i++) {
		getline(cin, s);
		auto arr = parsing(s, ",");

		int a = dict[arr[0]];
		int b = dict[arr[1]];
		int c = stoi(arr[2]);

		if (Find(a) == Find(b)) {
			if (c == 1) {
				Parent[Find(b)] = a;
				Parent[a] = a;
			}
			else {
				Parent[Find(a)] = b;
				Parent[b] = b;
			}

			continue;
		}

		if (c == 1)
			Union(a, b);
		else
			Union(b, a);
	}

	vector<string> res;
	for (int i = 1; i <= N; i++) {
		if (Find(i) == i)
			res.push_back(orig[i]);
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto& it : res)
		cout << it << '\n';
}