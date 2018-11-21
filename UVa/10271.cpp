#include <stdio.h>
#include <string.h>

int ary[5000], dp[1009], dp2[1009];
char chk[1009], chk2[1009];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, k, n, i, j, temp;
	scanf("%d", &count);
	while(count--)
	{
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		memset(chk, 0, sizeof(chk));
		memset(chk2, 0, sizeof(chk2));
		scanf("%d%d", &k, &n);
		for(i=n-1; i>-1; i--)
		{
			scanf("%d", &ary[i]);
		}
		for(i=1, k+=8; i<n; i++)
		{
			temp = ary[i] - ary[i-1];
			temp *= temp;
			for(j=k; j; j--)
			{
				if(chk[j])
				{
					dp[j] = min(dp[j], dp2[j]);
				}
				else if(chk2[j])
				{
					dp[j] = dp2[j];
					chk[j] = 1;
				}
				if(i + 2 > j * 3 && (j == 1 || chk[j-1]))
				{
					if(!chk2[j] || dp2[j] > dp[j-1] + temp)
					{
						dp2[j] = dp[j-1] + temp;
						chk2[j] = 1;
					}
				}
			}
		}
		if(!chk[k])
		{
			dp[k] = dp2[k];
		}
		printf("%d\n", min(dp[k], dp2[k]));
	}
	return 0;
}
