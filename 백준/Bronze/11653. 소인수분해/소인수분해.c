#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int number;

	scanf("%d", &number);

	int i;

	for (i = 2; number > 1;) {
		if ((number % i) == 0) {
			number /= i;
			printf("%d\n", i);
			continue;
		}
		i++;
	}

	return 0;
}