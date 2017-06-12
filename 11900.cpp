#include <stdio.h>

int main()
{
	int count, cas, n, p, q, i, ans, t;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &p, &q);
		for(i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if(ans < p && q >= t)
			{
				q -= t;
				ans++;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
