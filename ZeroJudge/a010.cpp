#include <stdio.h>

char str[10000];

int isthisaword(char ch)
{
	return (ch > 64 && ch < 91) || (ch > 96 && ch < 123);
}

int main()
{
	int i, words, isword;
	while(gets(str))
	{
		for(i=0, words=0, isword=0; str[i]; i++)
		{
			if(isthisaword(str[i]))
			{
				if(!isword)
				{
					isword = 1;
				}
			}
			else
			{
				words += isword;
				isword = 0;
			}
		}
		words += isword;
		printf("%d\n", words);
	}
	return 0;
}
