#include <bits/stdc++.h>
using namespace std;

int N;
int prices[1001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> prices[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			prices[i] = min(prices[i], prices[j] + prices[i - j]);
		}
	}
	cout << prices[N];
}