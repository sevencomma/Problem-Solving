#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
	int K, i;
	int building[1024] = { 0, };
	int building_check[1024] = { true, };
	int number;

	scanf("%d", &K);
	number = pow(2, K) - 1;
	
	for (i = 1; i <= number; i++) {
		scanf("%d", &building[i]);
		building_check[i] = false;
	}
	
	int cut = pow(2, K-1);

	for (int j = 0; j < K; j++) {
		for (i = 1; i <= number; i++) {
			if (i % cut == 0 && building_check[i] == false) {
				printf("%d ", building[i]);
				building_check[i] = true;
			}

		}
		cut = cut / 2;
		printf("\n");
	}

	return 0;
}