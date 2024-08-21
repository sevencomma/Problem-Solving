#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	sort(coins.rbegin(), coins.rend());

	int result = 0;

	for (auto it : coins) {
		while (K >= it) {
			K -= it;
			result++;
		}
	}

	cout << result;
}