#include <bits/stdc++.h>
using namespace std;

struct num {
	int value, index;
};

bool compare(num a, num b) {
	if (a.value == b.value)
		return a.index < b.index;
	return a.value < b.value;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<num> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i].value;
		numbers[i].index = i;
	}

	int w_index = 0;
	int w_value = numbers[0].value;
	for (int i = 0; i < n - 1; i++) {
		if (numbers[i].value > numbers[i].value) {
			w_index = numbers[i].index;
			w_value = numbers[i].value;
		}
	}
	sort(numbers.begin(), numbers.end(), compare);
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (res < numbers[i].index - i)
			res = numbers[i].index - i;
	}
	cout << res + 1;
}