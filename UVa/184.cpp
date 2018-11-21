#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;
int px[305], py[305];
int tbl[305];
int num[305];
int list[305][12];
int index[305];

struct data
{
	int p, q, x, y;
};

struct data ary[100000];

int arycomp(const void *p, const void *q)
{
	return ((struct data*)p)->x * ((struct data*)q)->y - ((struct data*)p)->y * ((struct data*)q)->x;
}

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)p] - px[*(int*)q];
}

int listcomp(const void *p, const void *q)
{
	int i, cmp, len1, len2;
	int *l1, *l2;
	l1 = list[*(int*)p];
	l2 = list[*(int*)q];
	len1 = num[*(int*)p];
	len2 = num[*(int*)q];
	for(i=0; i<len1&&i<len2; i++)
	{
		if(cmp=comp(l1+i, l2+i))
		{
			return cmp;
		}
	}
	return len1 - len2;
}

int main()
{
	int i, j, k, l;
	while(scanf("%d%d", &px[0], &py[0]) == 2)
	{
		n = m = 0;
		do
		{
			if(!px[n] && !py[n])
			{
				break;
			}
			for(i=0; i<n; i++)
			{
				ary[m].p = i;
				ary[m].q = n;
				ary[m].x = px[n] - px[i];
				ary[m++].y = py[n] - py[i];
			}
			n++;
		}while(scanf("%d%d", &px[n], &py[n]) == 2);
		if(!n)
		{
			break;
		}
		qsort(ary, m, sizeof(struct data), arycomp);
		for(i=0, k=0; i<m; i=j)
		{
			for(j=i+1; j<m; j++)
			{
				if(arycomp(ary+i, ary+j))
				{
					break;
				}
			}
			if(j - i > 1)
			{
				memset(tbl, 0, sizeof(tbl));
				num[k] = 0;
				for(l=i; l<j; l++)
				{
					printf("%d %d: %d %d\n", ary[l].p, ary[l].q, ary[l].x, ary[l].y);
					if(!tbl[ary[l].p])
					{
						tbl[ary[l].p] = 1;
						list[k][num[k]++] = ary[l].p;
					}
					if(!tbl[ary[l].q])
					{
						tbl[ary[l].q] = 1;
						list[k][num[k]++] = ary[l].q;
					}
				}
				index[k] = k;
				qsort(list[k], num[k++], sizeof(int), comp);
			}
		}
		if(k)
		{
			printf("The following lines were found:\n");
			qsort(index, k, sizeof(int), listcomp);
			for(i=0; i<k; i++)
			{
				for(j=0; j<num[index[i]]; j++)
				{
					printf("(%4d,%4d)", px[list[index[i]][j]], py[list[index[i]][j]]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("No lines were found\n");
		}
	}
	return 0;
}
