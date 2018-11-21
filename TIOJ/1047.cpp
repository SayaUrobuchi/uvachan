#include <stdio.h>
#include <string.h>

char buf[1000];

int calc(int p, int q)
{
	int i, star;
	for(i=p, star=-1; i<=q; i++)
	{
		if(buf[i] == '+')
		{
			return calc(p, i-1) | calc(i+1, q);
		}
		else if(buf[i] == '*')
		{
			star = i;
		}
	}
	if(star == -1)
	{
		if(buf[p] == '!')
		{
			return !calc(p+1, q);
		}
		else
		{
			return buf[p] - '0';
		}
	}
	else
	{
		return calc(p, star-1) & calc(star+1, q);
	}
}

int main()
{
	while(gets(buf))
	{
		if(strcmp(buf, "END") == 0)
		{
			break;
		}
		printf("%d\n", calc(0, strlen(buf)-1));
	}
	return 0;
}
