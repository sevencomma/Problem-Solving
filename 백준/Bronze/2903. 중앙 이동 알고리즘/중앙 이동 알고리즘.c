#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	//3 -> 5 -> 9 - > 17 -> 33
	// 어떻게 만드는지는 중요X, 그냥 만들어졌을때, 개수만 세면됨...

	int dott = 2;

	for (int i = 1; i <= N; i++) {
		dott = dott + dott - 1;
	}
	printf("%d", dott*dott);

	return 0;
}