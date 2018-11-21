#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int idx[105], cos[105];
char name[105][25];

int comp(const void *p, const void *q)
{
	return cos[*(int*)p]!=cos[*(int*)q]?(cos[*(int*)p]>cos[*(int*)q]?1:-1):strcmp(name[*(int*)p], name[*(int*)q]);
}

int main()
{
	int cas, count, i, n, p, q, t, c, tt, pp, pq;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &p, &q, &n);
		for(i=0; i<n; i++)
		{
			scanf("\n%[A-Z]:%d,%d", name[i], &pp, &pq);
			for(t=p, c=0; t!=q; )
			{
				tt = (t>>1);
				if(tt < q || pq>=pp*tt)
				{
					c += pp*(t-q);
					break;
				}
				t = tt;
				c += pq;
			}
			cos[i] = c;
			idx[i] = i;
		}
		qsort(idx, n, sizeof(idx[0]), comp);
		printf("Case %d\n", ++cas);
		for(i=0; i<n; i++)
		{
			printf("%s %d\n", name[idx[i]], cos[idx[i]]);
		}
	}
	return 0;
}
