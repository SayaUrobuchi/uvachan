#include <stdio.h>
#include <algorithm>

int dp[1000005], dq[1000005], ary[1005];

int main()
{
	int cnt, n, i, j, k, c, t, sum, half;
	while (scanf("%d", &n) == 1)
	{
		++cnt;
		dp[0] = cnt;
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		std::sort(ary, ary+n);
		half = (sum>>1);
		dq[0] = 0;
		for (i=0, j=0, c=1; i<n; i++)
		{
			for (k=c; k>=0; k--)
			{
				t = dq[k]+ary[i];
				if (t <= half && dp[t] != cnt)
				{
					dp[t] = cnt;
					dq[c++] = t;
					if (t > j)
					{
						j = t;
						if (j == half)
						{
							break;
						}
					}
				}
			}
			if (k >= 0)
			{
				break;
			}
		}
		printf("%d %d\n", j, sum-j);
	}
	return 0;
}
