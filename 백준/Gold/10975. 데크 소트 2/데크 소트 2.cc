#include <bits/stdc++.h>
using namespace std;

struct item {
	int idx, val, seq;
};

int N;
vector<item> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		arr[i].idx = i;
		cin >> arr[i].val;
	}

	sort(arr.begin(), arr.end(),
		[](const item& a, const item& b) {
			return a.val < b.val;
		});
	for (int i = 0; i < N; i++)
		arr[i].seq = i;

	sort(arr.begin(), arr.end(),
		[](const item& a, const item& b) {
			return a.idx < b.idx;
		});

	deque<item> dqs[50];
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int cur = arr[i].seq;
		bool inserted = false;
		for (int j = 0; j < cnt; j++) {
			if (cur + 1 == dqs[j].front().seq) {
				dqs[j].push_front(arr[i]);
				inserted = true;
				break;
			}
			else if (cur - 1 == dqs[j].back().seq) {
				dqs[j].push_back(arr[i]);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			dqs[cnt].push_back(arr[i]);
			cnt++;
		}
	}
	cout << cnt;
}