#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int i, j;
	int number;
	int num[1000];
	int temp;

	scanf("%d", &number);

	for (i = 0; i < number; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < number - 1; i++) {
		for (j = 0; j < number - i - 1; j++) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < number; i++)
		printf("%d\n", num[i]);

	return 0;
}