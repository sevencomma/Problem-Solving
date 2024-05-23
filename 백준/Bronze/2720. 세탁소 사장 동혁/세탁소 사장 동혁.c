#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int test_case;
	scanf("%d", &test_case);

	int quarter;
	int dime;
	int nickel;
	int penny;

	for (int i = 0; i < test_case; i++) {
		int cent;
		scanf("%d", &cent);

		quarter = cent / 25;
		cent %= 25;

		dime = cent / 10;
		cent %= 10;

		nickel = cent / 5;
		cent %= 5;

		penny = cent;

		printf("%d %d %d %d\n", quarter, dime, nickel, penny);
	}

	return 0;
}