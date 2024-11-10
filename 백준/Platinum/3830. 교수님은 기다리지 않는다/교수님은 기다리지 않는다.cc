#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c;
char t;
int parent[100001];
int Rank[100001];
int num[100001];

int Find(int x) {
	if (parent[x] == x)
		return x;
	int px = Find(parent[x]);
	num[x] += num[parent[x]];
	return parent[x] = px;
}

void Union(int a, int b, int w) {
	int x = Find(a), y = Find(b);
	if (x == y) return;

	if (Rank[x] > Rank[y]) {
		parent[y] = x;
		num[y] = num[a] - num[b] + w;
	}
	else {
		parent[x] = y;
		num[x] = num[b] - num[a] - w;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[x] + 1;
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		memset(num, 0, sizeof(num));
		memset(Rank, 0, sizeof(Rank));
		for (int i = 1; i <= N; i++)
			parent[i] = i;

		for (int i = 0; i < M; i++) {
			cin >> t;
			if (t == '!') {
				cin >> a >> b >> c;
				Union(a, b, c);
			}
			else if (t == '?') {
				cin >> a >> b;
				if (Find(a) == Find(b))
					cout << num[b] - num[a] << '\n';
				else
					cout << "UNKNOWN\n";
			}
		}
	}
}