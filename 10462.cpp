#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 2147483647

int qnum;
int queue[205];
int ex[205], ey[205], elen[205], index[205];
int parent[105];

int comp(const void *p, const void *q)
{
	return elen[*(int*)p] - elen[*(int*)q];
}

int getparent(int now)
{
	if(parent[now])
	{
		return parent[now]=getparent(parent[now]);
	}
	return now;
}

int main()
{
	int cas, count, n, m, i, j, c, e, max;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &ex[i], &ey[i], &elen[i]);
			index[i] = i;
		}
		qsort(index, m, sizeof(int), comp);
		memset(parent, 0, sizeof(parent));
		for(j=0, c=0, e=1, qnum=0; j<m&&e<n; j++)
		{
			if(getparent(ex[index[j]]) != getparent(ey[index[j]]))
			{
				parent[getparent(ex[index[j]])] = getparent(ey[index[j]]);
				c += elen[index[j]];
				queue[qnum++] = j;
				e++;
			}
		}
		if(e != n)
		{
			printf("Case #%d : No way\n", ++cas);
		}
		else
		{
			max = INF;
			if(m >= n)
			{
				for(i=0; i<qnum; i++)
				{
					memset(parent, 0, sizeof(parent));
					for(j=0, c=0, e=1; j<m&&e<n; j++)
					{
						if(j != queue[i] && getparent(ex[index[j]]) != getparent(ey[index[j]]))
						{
							parent[getparent(ex[index[j]])] = getparent(ey[index[j]]);
							c += elen[index[j]];
							e++;
						}
					}
					if(e == n && c < max)
					{
						max = c;
					}
				}
			}
			if(max == INF)
			{
				printf("Case #%d : No second way\n", ++cas);
			}
			else
			{
				printf("Case #%d : %d\n", ++cas, max);
			}
		}
	}
	return 0;
}
