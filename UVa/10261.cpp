#include <stdio.h>
#include <string.h>

int last[201][10001];
char chk[201][10001];

void recursion(int c, int now, int depth)
{
	if(!c)
	{
		printf("%d\n", depth);
		return;
	}
	recursion(c-1, last[c][now], depth+1);
	if(last[c][now] == now)
	{
		printf("port\n");
	}
	else
	{
		printf("starboard\n");
	}
}

int main()
{
	int count, n, m, i, c, s, sum;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		n *= 100;
		memset(chk, 0, sizeof(chk));
		c = 1;
		chk[0][0] = 1;
		sum = 0;
		while(scanf("%d", &m) == 1)
		{
			if(!m)
			{
				break;
			}
			sum += m;
			s = 0;
			if(sum <= n + n)
			{
				for(i=0; i<=sum; i++)
				{
					if(chk[c-1][i])
					{
						if(sum - i <= n)
						{
							chk[c][i] = 1;
							last[c][i] = i;
							s = 1;
						}
						if(i + m <= n)
						{
							chk[c][i+m] = 1;
							last[c][i+m] = i;
							s = 1;
						}
					}
				}
				if(s)
				{
					c++;
				}
				else
				{
					sum = n * 2 + 1;
				}
			}
		}
		for(i=10001, c--; i>-1; i--)
		{
			if(chk[c][i])
			{
				recursion(c, i, 0);
				break;
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
