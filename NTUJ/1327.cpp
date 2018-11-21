#include <stdio.h>
#include <string.h>

unsigned int dp[7900], dp2[7900];

int gcd(int a, int b)
{
	if(a % b)
	{
		return gcd(b, a%b);
	}
	return b;
}

int main()
{
	int count, n, m, mt, b, i, j, k, jt, wt, d1, d2, ans, left, right, w;
	unsigned int *p, *q, *t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &b, &n);
		wt = 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		p = dp;
		q = dp2;
		m = 0;
		mt = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &left, &right, &w);
			wt += w;
			memset(q, 0, sizeof(dp));
			for(j=left; j<=right; j++)
			{
				jt = j * w;
				d1 = (jt >> 5);
				d2 = (jt & 31);
				for(k=0; k<=m; k++)
				{
					q[k+d1] |= (p[k]<<d2);
					if(d2)
					{
						q[k+d1+1] |= (p[k]>>(32-d2));
					}
				}
			}
			t = p;
			p = q;
			q = t;
			mt += right*w;
			m = (mt >> 5);
		}
		b *= wt;
		for(i=b, j=b; ; i--, j++)
		{
			if(i >= 0 && (p[i>>5] & (1u<<(i&31))))
			{
				ans = b-i;
				break;
			}
			if(j <= mt && (p[j>>5] & (1u<<(j&31))))
			{
				ans = j-b;
				break;
			}
		}
		printf("%d/%d\n", ans/gcd(ans, wt), wt/gcd(ans, wt));
	}
	return 0;
}
