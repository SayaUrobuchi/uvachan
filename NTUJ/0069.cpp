#include <stdio.h>
#include <string.h>

char s[100];

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", s);
		for(i=strlen(s)-1; i>0; i--)
		{
			if(s[i] >= '5')
			{
				s[i-1]++;
			}
			s[i] = '0';
		}
		if(s[0] > '9')
		{
			s[0] -= 10;
			printf("1");
		}
		puts(s);
	}
	return 0;
}
