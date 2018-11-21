#include <stdio.h>
#include <string.h>

int a[10], b[10], tbl[10];
char str[10000][5], guess[10][5];

int main()
{
	int count, n, i, j, k, ans, corr, misplace, match;
	for(i=0; i<10000; i++)
	{
		sprintf(str[i], "%04d", i);
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s%d/%d", guess[i], &a[i], &b[i]);
		}
		for(i=0, ans=-1; i<10000; i++)
		{
			for(j=0, match=0; j<n; j++)
			{
				memset(tbl, 0, sizeof(tbl));
				for(k=0, corr=0; k<4; k++)
				{
					if(str[i][k] == guess[j][k])
					{
						corr++;
					}
					else
					{
						tbl[str[i][k]-48]++;
					}
				}
				for(k=0, misplace=0; k<4; k++)
				{
					if(str[i][k] != guess[j][k])
					{
						if(tbl[guess[j][k]-48])
						{
							tbl[guess[j][k]-48]--;
							misplace++;
						}
					}
				}
				if(corr != a[j] || misplace != b[j])
				{
					break;
				}
			}
			if(j == n)
			{
				if(ans == -1)
				{
					ans = i;
				}
				else
				{
					ans = 10000;
					break;
				}
			}
		}
		if(ans == -1)
		{
			printf("impossible\n");
		}
		else if(ans == 10000)
		{
			printf("indeterminate\n");
		}
		else
		{
			printf("%04d\n", ans);
		}
	}
	return 0;
}
