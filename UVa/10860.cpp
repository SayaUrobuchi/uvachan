#include <stdio.h>
#include <string.h>

int dp[10001], slen[51];
char ary[101][101], str[10001];

char scomp(char* s, char* s2, int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		if(s[i] != s2[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int cas, count, n, i, j, len;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%s%d", str, &n);
		len = strlen(str);
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
			slen[i] = slen[i+n] = strlen(ary[i]);
			for(j=0; j<slen[i]; j++)
			{
				ary[i+n][j] = ary[i][slen[i]-j-1];
			}
			if(scomp(str, ary[i], slen[i]))
			{
				dp[slen[i]] = 1;
			}
			else if(scomp(str, ary[i+n], slen[i]))
			{
				dp[slen[i]] = 1;
			}
		}
		for(i=1, n*=2; str[i]; i++)
		{
			if(dp[i])
			{
				for(j=0; j<n; j++)
				{
					if(i + slen[j] <= len && scomp(str+i, ary[j], slen[j]))
					{
						if(dp[i] + 1 < dp[i+slen[j]] || !dp[i+slen[j]])
						{
							dp[i+slen[j]] = dp[i] + 1;
						}
					}
				}
			}
		}
		if(dp[len])
		{
			printf("Set %d: %d.\n", ++cas, dp[len]);
		}
		else
		{
			printf("Set %d: Not possible.\n", ++cas);
		}
	}
	return 0;
}
