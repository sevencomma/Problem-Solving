#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, Q, a, b, c;

vector<ll> tree;

ll sum(int pos) {
	pos++;
	ll ret = 0;
	
	while (pos > 0) {
		ret += tree[pos];
		pos &= (pos - 1);
	}
	return ret;
}

void add(int pos, int val) {
	pos++;

	while (pos < tree.size()) {
		tree[pos] += val;
		pos += (pos & -pos);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	tree.resize(N + 1, 0);

	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			add(b - 1, c);
		else
			cout << sum(c - 1) - sum(b - 2) << '\n';
	}
}