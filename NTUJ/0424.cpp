#include <stdio.h>
#include <string.h>

int parent[50000], num[50000];

int getparent(int now)
{
	if(parent[now] == -1)
	{
		return now;
	}
	return parent[now]=getparent(parent[now]);
}

int main()
{
	int n, m, i, p, t, r;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(parent, -1, sizeof(parent));
		memset(num, -1, sizeof(num));
		for(i=0; i<m; i++)
		{
			scanf("%d", &r);
			for(p=-1; r--; )
			{
				scanf("%d", &t);
				if(p == -1)
				{
					p = t;
				}
				else
				{
					p = getparent(p);
					t = getparent(t);
					if(p != t)
					{
						num[p] += num[t];
						parent[t] = p;
					}
				}
			}
		}
		printf("%d\n", -num[getparent(0)]);
	}
	return 0;
}
