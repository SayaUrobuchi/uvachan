#include <stdio.h>
#include <string.h>

int map[100][100], dp[101][100];
char str[100][21];

int search(char* s, int right)
{
	int i;
	for(i=0; i<right; i++)
	{
		if(!strcmp(s, str[i]))
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	int cas, count, n, m, i, j, k, l, c;
	char s1[21], s2[21];
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		/*gets(str[0]);*/
		for(i=0; i<n; i++)
		{
			/*gets(str[i]);*/
			scanf("%s", str[i]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				map[i][j] = -1;
			}
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s%d", s1, s2, &c);
			i = search(s1, n);
			j = search(s2, n);
			if(map[i][j] == -1 || map[i][j] > c)
			{
				map[i][j] = c;
			}
		}
		for(i=0; i<n; i++)
		{
			dp[1][i] = map[0][i];
		}
		for(l=2; l<n; l++)
		{
			for(i=0; i<n; i++)
			{
				dp[l][i] = dp[l-1][i];
			}
			for(j=l; j<n; j++)
			{
				for(k=1; k<j; k++)
				{
					if(map[k][j] != -1 && dp[l-1][k] != -1 && (dp[l][j] > dp[l-1][k] + map[k][j] || dp[l][j] == -1))
					{
						dp[l][j] = dp[l-1][k] + map[k][j];
					}
				}
			}
		}
		printf("Scenario #%d\n", ++cas);
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &i);
			if(i > n - 2)
			{
				i = n - 2;
			}
			if(dp[i+1][n-1] != -1)
			{
				printf("Total cost of flight(s) is $%d\n", dp[i+1][n-1]);
			}
			else
			{
				printf("No satisfactory flights\n");
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
