#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char tbl[10001], h[3];
int ary[3][1000], uns[3][1000], anum[3], unum[3], pnum[3];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int cas, count, i, j, lim, tmp, tmp2;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<3; i++)
		{
			scanf("%d", &lim);
			anum[i] = lim;
			for(j=0; j<lim; j++)
			{
				scanf("%d", &tmp);
				ary[i][j] = tmp;
				tbl[tmp]++;
			}
		}
		for(i=0; i<3; i++)
		{
			lim = anum[i];
			tmp2 = 0;
			for(j=0; j<lim; j++)
			{
				tmp = ary[i][j];
				if(tbl[tmp] == 1)
				{
					uns[i][tmp2++] = tmp;
				}
			}
			unum[i] = tmp2;
		}
		printf("Case #%d:\n", ++cas);
		for(i=0; i<3; i++)
		{
			lim = unum[i];
			for(j=0; j<3; j++)
			{
				if(lim < unum[j])
				{
					break;
				}
			}
			if(j == 3)
			{
				printf("%d %d", i+1, lim);
				qsort(uns[i], lim, 4, comp);
				for(j=0; j<lim; j++)
				{
					printf(" %d", uns[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
