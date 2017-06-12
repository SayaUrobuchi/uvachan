#include <stdio.h>
#include <string.h>

char buf[2008];
double tbl[10];
double dp[11], dp2[11];

int main()
{
	int cas, n, i, j, digit, r;
	char *ptr;
	double *p1, *p2, *ptemp;
	double p;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n != 10)
		{
			break;
		}
		for(i=0; i<10; i++)
		{
			scanf("%d%lf", &digit, &p);
			tbl[digit] = p;
		}
		scanf("%d", &n);
		printf("Case %d:\n", ++cas);
		while(n--)
		{
			scanf("%s%d", buf, &r);
			memset(dp, 0, sizeof(dp));
			dp[0] = 1.0;
			for(ptr=buf, p1=dp, p2=dp2; *ptr; ptr++)
			{
				if(*ptr == '*')
				{
					for(j=0; j<10; j++)
					{
						p2[j] = p1[0] * tbl[j];
					}
					p2[j] = 0.0;
					for(i=1; i<11; i++)
					{
						for(j=0; j<10; j++)
						{
							p2[(i*10+j)%11] += p1[i] * tbl[j];
						}
					}
				}
				else
				{
					for(i=0, *ptr-='0'; i<11; i++)
					{
						p2[(i*10+(*ptr))%11] = p1[i];
					}
				}
				ptemp = p1;
				p1 = p2;
				p2 = ptemp;
			}
			printf("%.8lf\n", p1[r]);
		}
	}
	return 0;
}
