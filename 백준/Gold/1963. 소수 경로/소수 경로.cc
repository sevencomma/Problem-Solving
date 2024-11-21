#include <bits/stdc++.h>
using namespace std;

struct point {
	int n, cnt;
};
bool is_prime[10000];
int T, a, b;
bool visited[10000];

int bfs(int a, int b) {
	queue<point> q;
	q.push({ a, 0 });
	visited[a] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.n == b)
			return cur.cnt;

		int N[] = { cur.n / 1000, (cur.n / 100) % 10, (cur.n / 10) % 10, cur.n % 10 };

		for (int i = 0; i < 4; i++)
			for (int j = 1; j < 10; j++) {
				int cn = (N[i] + j) % 10;
				cn = N[0] * 1000 + N[1] * 100 + N[2] * 10 + N[3] + (cn - N[i]) * pow(10, 3 - i);

				if (cn >= 1000 && cn < 10000 && !visited[cn] && is_prime[cn]) {
					q.push({ cn, cur.cnt + 1 });
					visited[cn] = true;
				}
			}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 2; i < 10000; i++)
		is_prime[i] = true;
	for (int i = 2; i * i < 10000; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j < 10000; j += i)
				is_prime[j] = false;
		}
	}
	cin >> T;
	while (T--) {
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		int res = bfs(a, b);
		if (res == -1)
			cout << "Impossible\n";
		else
			cout << res << "\n";
	}
}