#include <bits/stdc++.h>
using namespace std;

int G, P;
vector<int> g;
int Parent[100001];

void Link(int x, int y) {
	if (x < y)
		Parent[y] = x;
	else
		Parent[x] = y;
}

int Find(int x) {
	if (x != Parent[x])
		Parent[x] = Find(Parent[x]);
	return Parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> G >> P;
	for (int i = 0; i <= G; i++)
		Parent[i] = i;

	g.resize(P);
	for (int i = 0; i < P; i++)
		cin >> g[i];

	int cnt = 0, cur;
	for (int i = 0; i < P; i++) {
		cur = g[i];
		if (Find(cur) == 0)
			break;

		Union(cur, Find(cur) - 1);
		cnt++;
	}
	cout << cnt;
}