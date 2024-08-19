#include <iostream>
#include <vector>

using namespace std;

int dp[1000001] = {-1,};

int min_of_three(int a, int b, int c) {
	int result = a < b ? a < c ? a : c : b < c ? b : c;
	return result;
}

void make_1(int x) {
	for (int i = 2; i <= x; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min_of_three(dp[i - 1], dp[i / 2], dp[i / 3]) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
}

int main(void)
{
	int X;
	cin >> X;

	make_1(X);

	cout << dp[X];
}