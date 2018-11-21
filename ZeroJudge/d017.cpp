#include <stdio.h>

char s[1000005];

int main()
{
	int cas, i, j, a, b, pa, pb;
	cas = 0;
	while(gets(s))
	{
		for(i=0, a=0, b=0; s[i]; i++)
		{
			if(s[i] == 'a')
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("AB Circle #%d:\n", ++cas);
		for(i=0; s[i]; i++)
		{
			for(j=i, pa=0, pb=0; s[j+1]; j++)
			{
				if(s[j] == 'a')
				{
					pa++;
				}
				else
				{
					pb++;
				}
				if(pa == b-pb || pb == a-pa)
				{
					printf("%d,%d\n", i, j+1);
				}
			}
		}
	}
	return 0;
}
