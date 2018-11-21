#include <stdio.h>
#include <string.h>

int choose[100];
char dp[1000001];

int main()
{
	int n, m, i, j, tmp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<m; i++)
		{
			scanf("%d", &choose[i]);
		}
		memset(dp, 1, n+1);
		for(i=0; i<n; i++)
		{
			if(dp[i])
			{
				for(j=0; j<m; j++)
				{
					tmp = i + choose[j];
					if(tmp > n)
					{
						continue;
					}
					dp[tmp] = 0;
					if(tmp == n)
					{
						break;
					}
				}
				if(j < m)
				{
					break;
				}
			}
		}
		if(dp[n])
		{
			printf("Ollie wins\n");
		}
		else
		{
			printf("Stan wins\n");
		}
	}
	return 0;
}
