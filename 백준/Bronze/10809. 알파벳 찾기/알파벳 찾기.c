#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int i , j;
	int locate[26];
	char s[100];
	int len;

	scanf("%s", s);
	len = strlen(s);

	for (i = 0; i < 26; i++)
		locate[i] = -1;
	
	for (i = 0; i < 26; i++) {
		for (j = 0; j < len; j++) {
			if (s[j] == 'a' + i) {
				locate[i] = j;
				break;
			}
		}
	}

	for (i = 0; i < 26; i++)
		printf("%d ", locate[i]);


	return 0;
}