#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1000000
bool isprime[MAX_NUM + 1];
bool is_ans[MAX_NUM + 1]; // a ~ b : b - a + 1 개
long long a, b;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (int i = 2; i * i <= MAX_NUM; i++) {
		if (isprime[i])
			for (int j = i * i; j <= MAX_NUM; j += i)
				isprime[j] = false;
	}

	memset(is_ans, true, sizeof(is_ans));
	for (int i = 2; i <= MAX_NUM; i++) {
		if (isprime[i]) {
			long long offset = (long long)i * i;
			long long temp = a / offset;
			for (long long cur = offset * temp; cur <= b; cur += offset) {
				if ((cur - a) >= 0)
					is_ans[cur - a] = false;
			}
		}
	}
	long long count = 0;
	for (int i = 0; i < b - a + 1; i++)
		if (is_ans[i])
			count++;
	cout << count;
}