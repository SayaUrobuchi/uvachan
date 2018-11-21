#include <stdio.h>

char s[1000000];

int main()
{
	int count, i, one, zero;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", s);
		for(i=0, one=0, zero=0; s[i]; i++)
		{
			if(s[i] == '0')
			{
				zero = 1;
			}
			else if(s[i] == '1')
			{
				one = 1;
			}
		}
		printf("%d\n", zero+one);
	}
	return 0;
}
