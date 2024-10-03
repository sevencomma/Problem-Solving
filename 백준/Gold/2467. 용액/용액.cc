#include <bits/stdc++.h>
using namespace std;

int N, temp;
vector<int> minus_nums;
vector<int> plus_nums;
vector<long long> sequence;

bool compare(int a, int b) {
	return (abs(a) < abs(b));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp < 0)
			minus_nums.push_back(temp);
		else
			plus_nums.push_back(temp);
	}
	if (minus_nums.size() == 0) {
		sort(plus_nums.begin(), plus_nums.end(), compare);
		cout << plus_nums[0] << ' ' << plus_nums[1];
		return 0;
	}
	if (plus_nums.size() == 0) {
		sort(minus_nums.begin(), minus_nums.end(), compare);
		cout << minus_nums[1] << ' ' << minus_nums[0];
		return 0;
	}

	for (int i = 0; i < minus_nums.size(); i++)
		sequence.push_back(minus_nums[i]);
	for (int i = 0; i < plus_nums.size(); i++)
		sequence.push_back(plus_nums[i]);

	sort(sequence.begin(), sequence.end(), compare);
	
	long long min_d = INT_MAX, n1, n2;
	for (int i = 0; i < sequence.size() - 1; i++) {
		if (min_d > abs(sequence[i] + sequence[i + 1])) {
			n1 = sequence[i], n2 = sequence[i + 1];
			min_d = abs(n1 + n2);
		}
	}
	if (n1 > n2) {
		temp = n1, n1 = n2, n2 = temp;
	}
	cout << n1 << ' ' << n2;
}