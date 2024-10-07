#include <bits/stdc++.h>
using namespace std;

bool is_prime[4000001];
vector<int> prime;

int main(void) {
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
		is_prime[i] = true;
	for (int i = 2; i * i <= N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;
		}
	}
	for (int i = 0; i <= N; i++)
		if (is_prime[i])
			prime.push_back(i);

	int count = 0, sum = 0, index = 0;
	while (index < prime.size() && sum < N)
		sum += prime[index++];
	for (int i = 0; i < prime.size(); i++) {
		if (sum > N)
			sum -= prime[i];
		else if (sum == N) {
			count++;
			sum -= prime[i];
		}
		while (index < prime.size() && sum < N)
			sum += prime[index++];
	}
	cout << count;
}