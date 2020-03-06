#include <stdio.h>
#include <string.h>

int M;
int cnt[128];
int c[1025][1025];
char s[1025];

int main()
{
	int i, j, k, res, sum, ans, len;
	while (scanf("%d%s", &M, s) == 2)
	{
		memset(cnt, 0, sizeof(cnt));
		for (i=0; s[i]; i++)
		{
			cnt[s[i]]++;
		}
		len = i;
		c[0][0] = 1;
		for (i=1; i<=len; i++)
		{
			c[i][0] = 1;
			for (j=1; j<=i; j++)
			{
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
			}
		}
		ans = 0;
		for (i=0; s[i]; i++)
		{
			for (j=32; j<s[i]; j++)
			{
				if (cnt[j])
				{
					cnt[j]--;
					for (k=32, res=1, sum=0; k<128; k++)
					{
						if (cnt[k])
						{
							res = (res * c[sum+cnt[k]][sum]) % M;
							sum += cnt[k];
						}
					}
					cnt[j]++;
					ans = (ans+res) % M;
				}
			}
			cnt[j]--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
