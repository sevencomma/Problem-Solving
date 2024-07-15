#include <iostream>
using namespace std;

int main()
{
	int M, N;
	int i;
	int startIndex = -1 , endIndex;
	int square[101] = { 0, };
	int sum = 0;
	cin >> M >> N;

	for (i = 0; i <= 100; i++) {
		square[i] = i * i;
		
		if (i * i >= M && startIndex == -1)
			startIndex = i;

		if (i * i >= N) {
			endIndex = i - 1;
			if (i * i == N)
				endIndex = i;
			break;
		}
	}

	for (i = startIndex; i <= endIndex; i++)
		sum += square[i];

	if (sum == 0) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << sum << endl;
	cout << square[startIndex];
}