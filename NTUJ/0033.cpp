#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parent[1005], list[1000005][2], map[1005][1005];

int comp(const void *p, const void *q)
{
	return map[*(int*)p][*(((int*)p)+1)] - map[*(int*)q][*(((int*)q)+1)];
}

int getroot(int now)
{
	if(parent[now])
	{
		return parent[now]=getroot(parent[now]);
	}
	return now;
}

int main()
{
	int n, m, i, j, p, q, c, ans;
	while(scanf("%d", &n) == 1)
	{
		memset(parent, 0, sizeof(parent));
		for(i=1, m=0; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] != -1 && j > i)
				{
					list[m][0] = i;
					list[m++][1] = j;
				}
			}
		}
		qsort(list, m, sizeof(list[0]), comp);
		for(i=0, ans=0, c=1; i<m&&c<n; i++)
		{
			p = list[i][0];
			q = list[i][1];
			if((p=getroot(p)) != (q=getroot(q)))
			{
				parent[p] = q;
				ans += map[list[i][0]][list[i][1]];
				c++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
