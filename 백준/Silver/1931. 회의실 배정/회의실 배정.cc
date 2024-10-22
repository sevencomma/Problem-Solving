#include <bits/stdc++.h>
using namespace std;

int n, sum;

struct t {
	int start, end;
};

bool compare(t a, t b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<t> T(n);
	for (int i = 0; i < n; i++)
		cin >> T[i].start >> T[i].end;
	sort(T.begin(), T.end(), compare);
	int endpoint = T[0].end;
	sum++;
	for (int i = 1; i < n; i++) {
		if (T[i].start < endpoint)
			continue;
		else {
			endpoint = T[i].end;
			sum++;
		}
	}
	cout << sum;
}