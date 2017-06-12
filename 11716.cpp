#include <stdio.h>
#include <string.h>

char s[1000005];

int main()
{
	int count, i, j, k, len;
	gets(s);
	sscanf(s, "%d", &count);
	while(count--)
	{
		gets(s);
		len = strlen(s);
		for(i=1; i*i<len; i++);
		if(i*i != len)
		{
			printf("INVALID\n");
			continue;
		}
		for(j=0; j<i; j++)
		{
			for(k=j; k<len; k+=i)
			{
				printf("%c", s[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
