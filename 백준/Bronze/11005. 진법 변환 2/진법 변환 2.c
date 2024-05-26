#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char N[50];
	int B;
	int sum;
	int i = 0;

	scanf("%d %d", &sum, &B);
	
	while (sum > 0) {
		int cal = sum % B;
		if (cal >= 10)
			N[i] = cal + 'A' - 10;
		else
			N[i] = cal + '0';
		i++;
		sum /= B;
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%c", N[j]);
	}

	return 0;
}