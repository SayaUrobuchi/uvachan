#include <stdio.h>

int ary[100005], sum[100005], dp[100005][20], tbl[20];

int min(int p, int q)
{
	return p < q ? p : q;
}

int findlog2(int num)
{
	int i;
	for(i=0; num>1; num>>=1, i++);
	return i;
}

int query(int p, int q)
{
	int temp;
	temp = findlog2(q-p+1);
	return min(dp[p][temp], dp[q-tbl[temp]+1][temp]);
}

int main()
{
	int n, m, i, j, k, l, r, tl, tr, left, right, center;
	long long ans, temp;
	freopen("123.txt", "r", stdin);
	for(i=0; i<20; i++)
	{
		tbl[i] = (1<<i);
	}
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum[i] = sum[i-1] + ary[i];
			dp[i][0] = ary[i];
		}
		for(k=1, m=findlog2(n); k<=m; k++)
		{
			for(i=1, j=i+(1<<k)-1; j<=n; i++, j++)
			{
				dp[i][k] = min(dp[i][k-1], dp[i+tbl[k-1]][k-1]);
			}
		}
		for(i=1, ans=0; i<=n; i++)
		{
			if(i > 1 && ary[i] == ary[i-1])
			{
				continue;
			}
			/*printf("%d\n", i);*/
			for(left=1, right=i-1, l=1; left<=right; )
			{
				/*printf("%d %d\n", left, right);*/
				if(left == right)
				{
					if(ary[left] < ary[i])
					{
						l = left + 1;
					}
					break;
				}
				center = ((left+right)>>1) + 1;
				if(query(center, right) < ary[i])
				{
					left = center;
					l = center + 1;
				}
				else
				{
					right = center - 1;
				}
			}
			for(left=i+1, right=n, r=n; left<=right; )
			{
				if(left == right)
				{
					if(ary[left] < ary[i])
					{
						r = left - 1;
					}
					break;
				}
				center = ((left+right)>>1);
				if(query(left, center) < ary[i])
				{
					right = center;
					r = center - 1;
				}
				else
				{
					left = center + 1;
				}
			}
			if((temp=(sum[r]-sum[l-1])*(long long)ary[i]) > ans)
			{
				ans = temp;
				tl = l;
				tr = r;
			}
		}
		printf("%I64d\n%d %d\n", ans, tl, tr);
	}
	return 0;
}
