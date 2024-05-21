#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char s[1000];
	scanf("%s", s);

	int n;
	scanf("%d", &n);

	printf("%c", s[n-1]);

	return 0;
}