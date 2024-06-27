#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char word[100] = { 0, };
	int count = 0;
							// c=  c-  dz=  d-  lj  nj  s=  z= 
	scanf("%s", word);

	for (int i = 0; i < 100; i++) {
		if (word[i] == 0)
			break;

		if (word[i] == 'c')
			if (word[i + 1] == '=' || word[i + 1] == '-') {
				i++;
				count++;
				continue;
			}
		if (word[i] == 'd') {
			if (word[i + 1] == '-') {
				i++;
				count++;
				continue;
			}
			else if (word[i + 1] == 'z' && word[i + 2] == '=') {
				i += 2;
				count++;
				continue;
			}
		}
		if (word[i] == 'l')
			if (word[i + 1] == 'j') {
				i++;
				count++;
				continue;
			}
		if (word[i] == 'n')
			if (word[i + 1] == 'j') {
				i++;
				count++;
				continue;
			}
		if (word[i] == 's')
			if (word[i + 1] == '=') {
				i++;
				count++;
				continue;
			}
		if (word[i] == 'z')
			if (word[i + 1] == '=') {
				i++;
				count++;
				continue;
			}
		count++;
	}
	printf("%d", count);

	return 0;
}