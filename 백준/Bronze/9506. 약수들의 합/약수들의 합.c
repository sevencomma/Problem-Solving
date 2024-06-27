#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;
	int sub[256] = { 0, };
	while (1) {
		int sum_of_sub = 0;
		int k = 0;
		scanf("%d", &n);

		if (n == -1)
			break;

		for (int i = 1; i < n; i++) {
			if ((n % i) == 0) {
				sub[k++] = i;
				sum_of_sub += i;
			}
		}
		
		if (n == sum_of_sub) {
			printf("%d = ", n);
			for (int j = 0; j < k-1; j++)
				printf("%d + ", sub[j]);
			printf("%d\n", sub[k-1]);
		}
		else
			printf("%d is NOT perfect.\n", n);
	}


	return 0;
}