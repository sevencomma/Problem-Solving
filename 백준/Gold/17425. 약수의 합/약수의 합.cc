#include <bits/stdc++.h>
using namespace std;

int nums[1000001];
long long nums_sum[1000001];

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	
	for (int i = 1; i <= 1000000; i++)
		for (int j = i; j <= 1000000; j += i)
			nums[j] += i;
		
	for (int i = 1; i <= 1000000; i++)
		nums_sum[i] = nums_sum[i-1] + nums[i];

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << nums_sum[n] << "\n";
	}
}