#include <stdio.h>

long long c[55][55];
char s1[100000], s2[100000];

void print(char *s, int t, int f)
{
	if(!t)
	{
		return;
	}
	if(f)
	{
		printf("*");
	}
	printf("%s", s);
	if(t != 1)
	{
		printf("^%d", t);
	}
}

int main()
{
	int cas, i, j, count, t;
	cas = 0;
	c[0][0] = 1;
	for(i=1; i<55; i++)
	{
		c[i][0] = 1;
		for(j=1; j<=i; j++)
		{
			c[i][j] = c[i-1][j-1]+c[i-1][j];
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		i = scanf("\n(%[a-z]+%[a-z])^%d", s1, s2, &t);
		printf("Case %d: ", ++cas);
		for(i=0; i<=t; i++)
		{
			if(i)
			{
				printf("+");
			}
			if(c[t][i] > 1)
			{
				printf("%lld*", c[t][i]);
			}
			print(s1, t-i, 0);
			print(s2, i, t-i);
		}
		printf("\n");
	}
	return 0;
}
