#include <stdio.h>
#include <string.h>

char tbl[100];

int main()
{
	int cas, n, i, j, g, y, r, flag, left, right;
	double l, chk;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		memset(tbl, 1, sizeof(tbl));
		tbl[29] = tbl[61] = 0;
		for(i=0; i<n; i++)
		{
			scanf("%lf%d%d%d", &l, &g, &y, &r);
			for(j=30; j<=60; j++)
			{
				chk = l / j;
				chk *= 3600;
				chk += 0.0000001;
				chk -= ((int)chk / (g+y+r)) * (g+y+r);
				tbl[j] &= (chk <= (g+y));
			}
		}
		printf("Case %d: ", ++cas);
		for(i=30, flag=0; i<=61; i++)
		{
			if(tbl[i-1])
			{
				if(tbl[i])
				{
					right = i;
				}
				else
				{
					if(left == right)
					{
						if(flag)
						{
							printf(", %d", left);
						}
						else
						{
							printf("%d", left);
						}
					}
					else
					{
						if(flag)
						{
							printf(", %d-%d", left, right);
						}
						else
						{
							printf("%d-%d", left, right);
						}
					}
					flag = 1;
				}
			}
			else
			{
				if(tbl[i])
				{
					left = right = i;
				}
			}
		}
		if(!flag)
		{
			printf("No acceptable speeds.");
		}
		printf("\n");
	}
	return 0;
}
