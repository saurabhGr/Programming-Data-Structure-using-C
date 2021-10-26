#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void BruteForce(char *text, char *pattern)
{
	int size1 = strlen(text);
	int size2 = strlen(pattern);
	int index2, index;
	for(index = 0; index <= size1 - size2; index++)
	{
		for(index2 = 0; index2 < size2; index2++)
			if(text[index + index2] != pattern[index2])
				break;
		if(index2 == size2)
			printf("pattern found at index %d\n", index);
	}
}

int main()
{
	char text[100], pattern[100];
	printf("Enter text string\n");
	gets(text);
	printf("Enter pattern string\n");
	gets(pattern);
	BruteForce(text, pattern);
}
