#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int result = 0;

	vector<int> price(N + 1);

	price[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	vector<int> each_of_best(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		each_of_best[i] = price[i];
		for (int j = i; j >= i / 2; j--) {
			each_of_best[i] = max(each_of_best[i], each_of_best[j] + each_of_best[i - j]);
		}
	}

	cout << each_of_best[N];
}