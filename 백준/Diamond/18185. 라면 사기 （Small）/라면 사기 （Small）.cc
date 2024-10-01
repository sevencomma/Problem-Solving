#include <bits/stdc++.h>
using namespace std;

struct point {
	int dummy, one, two, three;
};

int N, sum;
vector<point> amount;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	amount.resize(N);
	for (int i = 0; i < N; i++)
		cin >> amount[i].dummy;

	amount[0].one = amount[0].dummy;
	amount[0].dummy = 0;
	for (int i = 0; i < N; i++) {
		if (i + 1 < N && amount[i].one > 0 && amount[i + 1].dummy > 0) {
			int a = min(amount[i].one, amount[i + 1].dummy);
			amount[i].one -= a;
			amount[i].two += a;
			amount[i + 1].dummy -= a;
		}
		if (i - 1 >= 0 && amount[i - 1].two > 0 && amount[i + 1].dummy > 0) {
			int b = min(amount[i - 1].two, amount[i + 1].dummy);
			amount[i - 1].two -= b;
			amount[i - 1].three += b;
			amount[i + 1].dummy -= b;
		}
		if (i + 1 < N) {
			amount[i + 1].one = amount[i + 1].dummy;
			amount[i + 1].dummy = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		sum += amount[i].one * 3 + amount[i].two * 5 + amount[i].three * 7;
	}
	cout << sum;
}