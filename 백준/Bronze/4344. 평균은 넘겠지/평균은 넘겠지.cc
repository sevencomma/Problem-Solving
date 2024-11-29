#include <bits/stdc++.h>
using namespace std;

int T, N, cnt;
double aver;

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N;
		cnt = aver = 0;
		vector<double> temp(N);
		for (int i = 0; i < N; i++) {
			cin >> temp[i];
			aver += temp[i];
		} aver /= N;
		for (int i = 0; i < N; i++)
			if (aver < temp[i])
				cnt++;
		printf("%.3f%%\n", (double)cnt / N * 100);
	}
}