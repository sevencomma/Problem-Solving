#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	/*	1					1
		2~7		7 - 2 + 1 = 6	1 + 6		1
		8~19		12		1 + 6 + 12	3
		20~37		18		1 + 6 + 12 + 18		6
		38~61		24		1 + 6 + 12 + 18 + 24		10
		1 + 6 * (N - 1) * (N) / 2
	*/

	int i;
	for (i = 1; i < 18258; i++) {
		if (i == 1)
			N -= 1;
		else
			N -= 6*(i-1);
		if (N <= 0)
			break;
	}
	printf("%d", i);

	return 0;
}