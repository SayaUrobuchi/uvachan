#include <stdio.h>

char s[10000005], s2[10000005];

int main()
{
	int count, f, cas;
	char *p1, *p2;
	cas = 0;
	gets(s);
	sscanf(s, "%d", &count);
	while(count--)
	{
		gets(s);
		gets(s2);
		f = 0;
		for(p1=s, p2=s2; *p1&&*p2; )
		{
			while(*p1&&*p1==' ')
			{
				f = 1;
				p1++;
			}
			if(*p1 != *p2)
			{
				break;
			}
			p1++;
			p2++;
		}
		if(!(*p2) && *p1)
		{
			while(*p1&&*p1==' ')
			{
				f = 1;
				p1++;
			}
		}
		if(!(*p1) && !(*p2))
		{
			if(f)
			{
				printf("Case %d: Output Format Error\n", ++cas);
			}
			else
			{
				printf("Case %d: Yes\n", ++cas);
			}
		}
		else
		{
			printf("Case %d: Wrong Answer\n", ++cas);
		}
	}
	return 0;
}
