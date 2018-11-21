#include <stdio.h>

int steak[100005], beef[100005];

int main()
{
	int n, m, d, h, dd, dh;
	long long temp, ans;
	while(scanf("%d", &n) == 1)
	{
		scanf("%d", &h);
		steak[1] = h;
		beef[1] = 0;
		for(m=1, d=0, ans=0; n; n--)
		{
			scanf("%d%d", &dd, &dh);
			h += dh;
			d += dd;
			for(; m>0&&steak[m]>h; m--)
			{
				if((temp=(long long)(d-beef[m]) * steak[m]) > ans)
				{
					ans = temp;
				}
			}
			steak[++m] = h;
			beef[m] = d;
		}
		for(; m>0; m--)
		{
			if((temp=(long long)(d-beef[m]) * steak[m]) > ans)
			{
				ans = temp;
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
