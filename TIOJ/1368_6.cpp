#include <stdio.h>

int ary[100005], steak[100005];
long long sum[100005];

int main()
{
	int n, m, i, tl, tr;
	long long temp, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, m=0, ans=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum[i] = sum[i-1] + ary[i];
			for(; m>0&&ary[steak[m]]>ary[i]; m--)
			{
				if((temp=(sum[i-1]-sum[steak[m-1]])*ary[steak[m]]) > ans)
				{
					ans = temp;
					tl = steak[m-1]+1;
					tr = i-1;
				}
			}
			steak[++m] = i;
		}
		for(; m>0; m--)
		{
			if((temp=(sum[i-1]-sum[steak[m-1]])*ary[steak[m]]) > ans)
			{
				ans = temp;
				tl = steak[m-1]+1;
				tr = i-1;
			}
		}
		printf("%I64d\n%d %d\n", ans, tl, tr);
	}
	return 0;
}
