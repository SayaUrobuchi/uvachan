#include <stdio.h>

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, count, n, i, x1, x2, y1, y2, p, q, r, s, flag;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
		for(i=1, flag=1; i<n; i++)
		{
			scanf("%d%d%d%d", &p, &q, &r, &s);
			if(flag)
			{
				x1 = max(x1, p);
				y1 = max(y1, q);
				x2 = min(x2, r);
				y2 = min(y2, s);
				flag = (x2 > x1 && y2 > y1);
			}
		}
		if(flag)
		{
			printf("Case %d: %d\n", ++cas, (x2-x1)*(y2-y1));
		}
		else
		{
			printf("Case %d: 0\n", ++cas);
		}
	}
	return 0;
}
