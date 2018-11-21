#include <stdio.h>
#include <string.h>

int used[105][105], dp[105][105];
char item[105][25];

int recurs(int p, int q)
{
	int i, t;
	if(p > q)
	{
		return 0;
	}
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(item[q][0] < 97)
	{
		return dp[p][q]=recurs(p, q-1);
	}
	dp[p][q] = recurs(p, q-1) + 1;
	for(i=q-1; i>=p; i--)
	{
		if(strcmp(item[i], item[q]) == 0)
		{
			t = recurs(p, i) + recurs(i+1, q-1);
			if(t < dp[p][q])
			{
				dp[p][q] = t;
			}
		}
		else if(item[i][0] < 97)
		{
			break;
		}
	}
	return dp[p][q];
}

int main()
{
	int cas, count, n, i;
	scanf("%d", &count);
	cas = 0;
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", &item[i]);
		}
		memset(used, 0, sizeof(used));
		printf("Case %d: %d\n", ++cas, recurs(0, n-1));
	}
	return 0;
}
