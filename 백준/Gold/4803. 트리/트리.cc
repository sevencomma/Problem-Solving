#include <bits/stdc++.h>
using namespace std;

int Parent[501];
int Rank[501];
int case_n, N, M, cnt, a, b;

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		Parent[y] = x;
	else {
		Parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[y] + 1;
	}
}

int Find(int x) {
	if (Parent[x] != x)
		Parent[x] = Find(Parent[x]);
	return Parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		case_n++;

		for (int i = 1; i <= N; i++)
			Parent[i] = i;
		cnt = 0;
		vector<int> cycle_list;
		set<int> cycle;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			if (Find(a) == Find(b))
				cycle_list.push_back(Find(a));
			else
				Union(a, b);
		}
		for (auto& it : cycle_list)
			cycle.insert(Find(it));
		for (int i = 1; i <= N; i++)
			if (Parent[i] == i)
				cnt++;
		cnt -= cycle.size();
		
		cout << "Case " << case_n << ": ";
		if (cnt == 0)
			cout << "No trees.\n";
		else {
			if (cnt == 1)
				cout << "There is one tree.\n";
			else
				cout << "A forest of " << cnt << " trees.\n";
		}
	}
}