#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long N, M;

	cin >> N >> M;

	if (N / 2 < M) {
		M = N - M;
	}

	int count = 0;
	for (long long i = 5; i <= N; i *= 5) {
		int a = (N / i);
		int b = (N - M) / i;

		if (a == 0)
			break;

		count += (a - b);
	}

	if (M >= 5) {
		for (long long i = 5; i <= M; i *= 5) {
			int a = (M / i);
			
			if (a == 0)
				break;

			count -= a;
		}
	}

	int count_two = 0;
	for (long long i = 2; i <= N; i *= 2) {
		int a = (N / i);
		int b = (N - M) / i;

		if (a == 0)
			break;
		count_two += (a - b);
	}

	if (M >= 2) {
		for (long long i = 2; i <= M; i *= 2) {
			int a = (M / i);

			if (a == 0)
				break;

			count_two -= a;
		}
	}
	
	int result = (count < count_two) ? count : count_two;
	cout << result;
}