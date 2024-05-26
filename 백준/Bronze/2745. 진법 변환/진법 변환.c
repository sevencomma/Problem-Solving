#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char N[100];
	int B;
	int sum = 0;

	scanf("%s %d", N, &B);

	int len = strlen(N);

	for (int i = 0; i < len; i++) {
		int digit;
		if (N[i] >= '0' && N[i] <= '9')
			digit = N[i] - '0';
		else if (N[i] >= 'A' && N[i] <= 'Z')
			digit = N[i] - 'A' + 10;

		sum += digit * pow(B, len - i - 1);
	}
	printf("%d", sum);

	return 0;
}