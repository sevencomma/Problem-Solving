#include <bits/stdc++.h>
using namespace std;

struct point {
	long long dummy, one, two, three;
};
long long N, B, C;
vector<point> sequence;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> B >> C;
	sequence.resize(N);
	for (int i = 0; i < N; i++)
		cin >> sequence[i].dummy;
	long long sum = 0;
	if (B <= C) {
		for (auto it : sequence)
			sum += B * it.dummy;
		cout << sum;
		return 0;
	}

	sequence[0].one = sequence[0].dummy;
	sequence[0].dummy = 0;
	for (int i = 0; i < N - 1; i++) {
		if (sequence[i].one > 0 && sequence[i + 1].dummy > 0) {
			int temp = min(sequence[i].one, sequence[i + 1].dummy);
			sequence[i].two = temp;
			sequence[i].one -= temp;
			sequence[i + 1].dummy -= temp;
		}
		if (i > 0 && sequence[i - 1].two > 0 && sequence[i + 1].dummy > 0) {
			int temp = min(sequence[i - 1].two, sequence[i + 1].dummy);
			sequence[i - 1].three = temp;
			sequence[i - 1].two -= temp;
			sequence[i + 1].dummy -= temp;
		}
		if (sequence[i + 1].dummy > 0) {
			sequence[i + 1].one = sequence[i + 1].dummy;
			sequence[i + 1].dummy = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		sum += B * sequence[i].one + (B + C) * sequence[i].two + (B + 2 * C) * sequence[i].three;
	}
	cout << sum;
}