#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int N, Q, q, i, x;
int limitM[MAXN];
int curM[MAXN];

int Parent[MAXN];

void Link(int x, int y) {
	if (x > y)
		swap(x, y);
	Parent[x] = y;
}

int Find(int x) {
	if (Parent[x] != x) {
		Parent[x] = Find(Parent[x]);
	}
	return Parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> limitM[i];
		Parent[i] = i;
	}

	for (int j = 0; j < Q; j++) {
		cin >> q >> i;
		if (q == 1) {
			cin >> x;
			int p = Find(i);

			while (x > limitM[p] - curM[p]) {
				x -= limitM[p] - curM[p];
				curM[p] = limitM[p];
				if (p == N) break;
				int next = Find(p + 1);
				Link(p, next);
				p = next;
			}

			if (p <= N) {
				curM[p] += x;
				if (p == N)
					curM[p] = min(curM[p], limitM[p]);
			}
		}
		else {
			cout << curM[i] << '\n';
		}
	}
}