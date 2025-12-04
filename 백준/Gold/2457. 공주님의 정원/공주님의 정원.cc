#include <bits/stdc++.h>
using namespace std;

int N, a, b, c, d, res;
vector<pair<int, int>> endLine[13][33];
priority_queue<pair<int, int>> pq; // maxHeap

void shoot(int a, int b, int c, int d) {
	// a월 b일부터 c월 d일까지 pq에 insert

	for (int i = a; i <= c; i++) {
		int start = 1;
		int end = 31;

		if (i == a) start = b;
		if (i == c) end = d;

		for (int j = start; j <= end; j++) {
			for (auto& it : endLine[i][j])
				pq.push(it);
		}
	}
}

bool lessThanOrEqual(pair<int, int> a, pair<int, int> b) {
	return a <= b;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		endLine[a][b].push_back({ c, d });
	}

	int bm = 1, bd = 0;
	int cm = 3, cd = 1;
	shoot(bm, bd, cm, cd);
	tie(bm, bd) = { cm, cd };
	bd++;

	while (cm < 12) {
		if (pq.empty()) {
			cout << 0;
			return 0;
		}
		auto it = pq.top();

		if (lessThanOrEqual(it, { cm, cd })) {
			cout << 0;
			return 0;
		}

		tie(cm, cd) = it;
		pq.pop();
		res++;

		shoot(bm, bd, cm, cd);
		tie(bm, bd) = { cm, cd };
		bd++;
	}

	cout << res;
}