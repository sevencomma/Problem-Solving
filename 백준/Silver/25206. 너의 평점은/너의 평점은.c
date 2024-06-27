#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char subname[51];
	double credit;
	char grade[3];

	double credit_sum = 0;
	double temp;
	double result = 0.0;

	for (int i = 0; i < 20; i++) {
		scanf("%s %lf %s", subname, &credit, grade);

		if (grade[0] == 'P')
			continue;
		
		credit_sum += credit;

		if (grade[0] == 'F')
			continue;

		if (grade[0] == 'A')
			temp = 4;
		else if (grade[0] == 'B')
			temp = 3;
		else if (grade[0] == 'C')
			temp = 2;
		else
			temp = 1;

		if (grade[1] == '+')
			temp += 0.5;

		result += (temp * credit);
	}
	

	printf("%lf", result / credit_sum);

	return 0;
}