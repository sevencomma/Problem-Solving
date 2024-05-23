#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int A, B, V;
	int result;
	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0)
		result = (V - A) / (A - B) + 1;
	else
		result = (V - A) / (A - B) + 1 + 1;

	printf("%d", result);

	return 0;
}