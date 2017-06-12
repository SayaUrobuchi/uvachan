#include <stdio.h>

int ary[1000005];

int main()
{
	int n, i, tt, last, ans, f, fin;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, ans=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ary[n] = ary[0];
		ary[n+1] = ary[1];
		for(i=1; i<=n; i++)
		{
			if(ary[i-1] < ary[i] && ary[i+1] < ary[i])
			{
				ans++;
			}
			else if(ary[i-1] > ary[i] && ary[i+1] > ary[i])
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
