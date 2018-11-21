#include <stdio.h>
#include <string.h>

int list[65536], step[65536], num[20], map[15][15], dp1[4096], dp2[4096];

int main()
{
	int n, m, i, j, k, l, s, ans, *p, *q, *tmp;
	list[0] = 0;
	step[0] = 0;
	for(i=0, j=1; i<j; i++)
	{
		num[step[i]] = i;
		if(step[i] == 13)
		{
			break;
		}
		list[j] = list[i];
		step[j++] = step[i] + 1;
		if(!i || (list[i] & (1<<step[i]-1)) == 0)
		{
			list[j] = list[i] + (1<<step[i]);
			step[j++] = step[i] + 1;
		}
	}
	for(i=0; i<=13; i++)
	{
		printf("%d\n", num[i]);
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		memset(dp1, 0, sizeof(dp1));
		p = dp1;
		q = dp2;
		for(i=0, l=num[m]; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				for(k=num[m-1]+1; k<=l; k++)
				{
					s = list[k];
					q[s] = 0;
					if(i == 0 && s >= (1<<(j+1)))
					{
						continue;
					}
					if(s & (1<<j))
					{
						if(map[i][j])
						{
							if(i || j)
							{
								q[s] = p[s-(1<<j)];
							}
							else
							{
								q[s] = 1;
							}
						}
					}
					else
					{
						if(i || j)
						{
							q[s] = p[s] + p[s+(1<<j)];
							if(q[s] >= 100000000)
							{
								q[s] -= 100000000;
							}
						}
						else
						{
							q[s] = 1;
						}
					}
					printf("%d %d, %d: %d\n", i, j, s, q[s]);
				}
				tmp = p;
				p = q;
				q = tmp;
			}
		}
		for(i=num[m-1]+1, ans=0; i<=num[m]; i++)
		{
			ans += p[list[i]];
			printf("P %d %d\n", i, p[list[i]]);
			if(ans >= 100000000)
			{
				ans -= 100000000;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
