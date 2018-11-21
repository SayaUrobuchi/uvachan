#include <stdio.h>
#include <string.h>

int tbl[128][10005], cnt[128], dp[1000005];
char s1[1000005], s2[1000005];

int main()
{
	int count, n, i, j, k, l, ans, fans, c;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		scanf("%s", s1);
		memset(cnt, 0, sizeof(cnt));
		for(i=0; s1[i]; i++)
		{
			tbl[s1[i]][cnt[s1[i]]++] = i;
		}
		for(i=0, fans=0; i<n; i++)
		{
			scanf("%s", s2);
			dp[0] = -1;
			ans = 0;
			for(j=0; s2[j]; j++)
			{
				k = cnt[(c=s2[j])]-1;
				for(l=ans; l>=0&&k>=0; )
				{
					if(tbl[c][k] > dp[l])
					{
						if(l == ans)
						{
							ans++;
						}
						dp[l+1] = tbl[c][k];
						k--;
					}
					else
					{
						l--;
					}
				}
			}
			if(ans > fans)
			{
				fans = ans;
			}
		}
		printf("%d\n", fans);
	}
	return 0;
}
