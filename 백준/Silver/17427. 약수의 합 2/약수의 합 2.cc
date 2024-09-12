#include <bits/stdc++.h>
using namespace std;

int nums[1000001];

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		
		for (int j = i; j <= N; j += i) {
			nums[j] += i;
		}
	}

	long long int result = 0;
	for (int i = 1; i <= N; i++) {
		result += nums[i];
	}
	cout << result;
}