#include <stdio.h>
#include <algorithm>

int dp[1000005], dq[1000005], lnk[510005], ary[1005];

int main()
{
	int cnt, n, i, j, k, c, t, ss, sum, half, quad, over;
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
		quad = (half>>1);
		over = 0;
		dq[0] = 0;
		ss = 0;
		for (i=0, j=0, c=1; i<n&&(n<20||c+1<quad); i++)
		{
			ss += ary[i];
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
							over = 1;
							break;
						}
					}
				}
			}
			if (over)
			{
				break;
			}
		}
		if (!over && n >= 20)
		{
			for (k=half, t=0; k>=0; k--)
			{
				if (dp[k] != cnt)
				{
					lnk[t] = k;
					t = k;
				}
			}
			for (; i<n; i++)
			{
				ss += ary[i];
				for (k=0, t=lnk[k]; t; k=t, t=lnk[t])
				{
					if (t >= ary[i])
					{
						if (t+(sum-ss) < half)
						{
							break;
						}
						if (dp[t-ary[i]] == cnt)
						{
							lnk[k] = lnk[t];
							dp[t] = cnt;
							if (t > j)
							{
								j = t;
								if (j == half)
								{
									over = 1;
									break;
								}
							}
						}
					}
					else
					{
						break;
					}
				}
				if (over)
				{
					break;
				}
			}
		}
		printf("%d %d\n", j, sum-j);
	}
	return 0;
}
