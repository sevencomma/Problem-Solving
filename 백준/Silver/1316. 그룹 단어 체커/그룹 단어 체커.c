#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int number;
	int count = 0;
	bool check;

	scanf("%d", &number);

	for (int i = 0; i < number; i++) {
		check = true;
		char str[100];
		scanf("%s", str);
		int len = strlen(str);

		char temp[100];
		int n = 0;
		temp[n++] = str[0];
		
		for (int k = 1; k < len; k++) {
			if (str[k] == str[k - 1])
				continue;
			else
				temp[n++] = str[k];
		}

		for (int j = 0; j < n; j++) {
			for (int h = j; h < n; h++) {
				if (h == j)
					continue;
				if (temp[j] == temp[h])
					check = false;
			}
		}
		if (check == true)
			count++;
	}
	
	printf("%d", count);

	return 0;
}