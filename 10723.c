#include <stdio.h>
#include <string.h>

int lcs[35][35], dp[35][35];
char chk[35][35], str[36], str2[36];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

unsigned int backtracing(int n, int m, int num)
{
	int i, j;
	unsigned int count, map[35][35];
	memset(map, 0, sizeof(map));
	map[n][m] = 1;
	count = 0;
	for(i=n; i>-1; i--)
	{
		for(j=m; j>-1; j--)
		{
			if(lcs[i][j] != num)
			{
				break;
			}
			if(i && j && str[i-1] == str2[j-1])
			{
				count += backtracing(i-1, j-1, num-1) * map[i][j];
			}
			else if(!i && !j)
			{
				count += 1 * map[i][j];
			}
			else
			{
				if(i)
				{
					map[i-1][j] += map[i][j];
				}
				if(j)
				{
					map[i][j-1] += map[i][j];
				}
			}
		}
		if(j == m)
		{
			break;
		}
	}
	return count;
}

int main()
{
	int cas, count, i, j, n, m;
	cas = 0;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		gets(str2);
		n = strlen(str);
		m = strlen(str2);
		memset(chk, 0, sizeof(chk));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(str[i] == str2[j])
				{
					lcs[i+1][j+1] = lcs[i][j] + 1;
				}
				else
				{
					lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
				}
			}
		}
		printf("Case #%d: %d %u\n", ++cas, n+m-lcs[i][j], backtracing(i, j, lcs[i][j]));
	}
	return 0;
}
