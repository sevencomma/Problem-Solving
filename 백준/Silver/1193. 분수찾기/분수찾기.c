#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 1; i < 4480; i++) {
		n -= i;

		if (n <= 0)
			break;
	}
	
	n += i;

	int first, last;

	if (i % 2 == 0) {
		first = 1;
		last = i;
		n--;
	}
	else{
		first = i;
		last = 1;
		n--;
	}
	
	for (int j = 0; j < n; j++) {
		if (i % 2 == 0) {
			first++;
			last--;
		}
		else {
			first--;
			last++;
		}
	}
	printf("%d/%d", first, last);

	return 0;
}