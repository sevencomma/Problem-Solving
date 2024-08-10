#include <iostream>
#include <vector>

using namespace std;

int prime[1000001] = { 0, };

int main(void)
{
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	
	
	prime[0] = 1;
	prime[1] = 1;
	prime[2] = 0;

	for (int i = 2; i * i <= N; i++) {
		if (prime[i])
			continue;

		for (int j = i * i; j <= N; j += i)
			prime[j] = 1;
	}

	for (int i = M; i <= N; i++) {
		if (!prime[i])
			cout << i << "\n";
	}
}