#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count, num;
	int result = 0;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%1d", &num);
		result += num;
	}
	printf("%d", result);

	return 0;
}