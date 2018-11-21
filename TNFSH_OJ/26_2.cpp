#include <stdio.h>

int dp[3005];
int an[128], pa[128], ary[128][3005];
char s[3005];

int main()
{
	int count, len, i, j, k, a, c, d, ans, t, p;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", &s);
		for (i='A'; i<='Z'; i++)
		{
			an[i] = 0;
			pa[i] = 0;
		}
		for (len=0; s[len]; len++)
		{
			ary[s[len]][an[s[len]]++] = len;
		}
		for (i=0, d=-1, ans=0; i<len; i++)
		{
			c = s[i];
			k = d;
			p = ary[c][pa[c]];
			for (j=pa[c]+1; j<an[c]; j++)
			{
				t = ary[c][j];
				for (; k>=0&&t>=dp[k]; k--);
				dp[k+1] = t;
				if (k+1 > d)
				{
					d = k+1;
				}
				a = ((k+2)<<1)+(p+1<t);
				if (a > ans)
				{
					ans = a;
				}
			}
			++pa[c];
		}
		printf("%d\n", ans);
	}
	return 0;
}
