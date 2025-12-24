#include <bits/stdc++.h>
using namespace std;

int a, b, c, cnt;

int main(void) {
	while (1) {
		cin >> a >> b >> c;
		if (a == 0) break;

		printf("Triangle #%d\n", ++cnt);

		if ((a == -1 && b >= c) ||
			(b == -1 && a >= c)) {
			printf("Impossible.\n\n");
			continue;
		}

		char ch;
		double res;
		if (a == -1) {
			res = sqrt(pow(c, 2) - pow(b, 2));
			ch = 'a';
		}
		else if (b == -1) {
			res = sqrt(pow(c, 2) - pow(a, 2));
			ch = 'b';
		}
		else {
			res = sqrt(pow(a, 2) + pow(b, 2));
			ch = 'c';
		}

		printf("%c = %.3f\n\n", ch, res);
	}
}