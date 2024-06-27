#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--)
			printf(" ");
		for (int k = 0; k < (i+1)*2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int k = 0; k < (n - i) * 2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	

	return 0;
}