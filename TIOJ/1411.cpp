#include <stdio.h>
#include <string.h>

int tbl[2000005];

int main()
{
	int p, i, neg, ans, now;
	while(scanf("%d", &p) == 1)
	{
		memset(tbl, -1, p*2*sizeof(int));
		tbl[p] = 0;
		for(i=1, neg=0, ans=1; i<=p; i++)
		{
			scanf("%d", &now);
			if(now > 0)
			{
				neg++;
			}
			else if(now < 0)
			{
				neg--;
			}
			if(tbl[neg+p] == -1)
			{
				tbl[neg+p] = i;
			}
			else
			{
				if(i-tbl[neg+p] > ans)
				{
					ans = i-tbl[neg+p];
				}
			}
			/*printf("neg::%d\n", neg);*/
		}
		printf("%d\n", ans);
	}
	return 0;
}
