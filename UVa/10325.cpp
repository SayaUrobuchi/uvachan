#include <stdio.h>
#include <stdlib.h>

int ary[15], n, m, flag, ans, limit;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int gcd(int p, int q)
{
	while((p%=q)&&(q%=p));
	return p+q;
}

void dfs(int last, int depth, long long lcm)
{
	int i;
	if(lcm > n)
	{
		return;
	}
	if(depth == limit)
	{
		ans += flag * (n/lcm);
		return;
	}
	for(i=last+1; i<m; i++)
	{
		dfs(i, depth+1, (lcm/gcd(lcm, ary[i]))*ary[i]);
	}
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<m; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = n;
		for(limit=0, flag=1; limit<15; limit++)
		{
			flag = -flag;
			for(i=0; i<m-limit; i++)
			{
				dfs(i, 0, ary[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
