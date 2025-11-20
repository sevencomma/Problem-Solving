#include <bits/stdc++.h>
using namespace std;

int N, M, x;
bool vip[41];
int cache[41]; // i명 연속할때 그거 경우의수

void init() {
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= N; i++)
		cache[i] = cache[i - 1] + cache[i - 2];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		vip[x] = true;
	}
	init();
	vector<int> con;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (vip[i]) {
			if (cnt != 0)
				con.push_back(cnt);
			cnt = 0;
			continue;
		}
		cnt++;
	}
	if (cnt > 0)
		con.push_back(cnt);

	int res = 1;
	for (auto& it : con)
		res *= cache[it];
	cout << res;
}