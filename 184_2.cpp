#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int px[305], py[305];
int index[305];
int map[305][305];
int num[90000];
int list[90000][12];
int lindex[90000];

int pcomp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)p] - px[*(int*)q];
}

int lcomp(const void *p, const void *q)
{
	int i, l, cmp;
	int *list1, *list2;
	if(num[*(int*)p] < num[*(int*)q])
	{
		l = num[*(int*)p];
	}
	else
	{
		l = num[*(int*)q];
	}
	list1 = list[*(int*)p];
	list2 = list[*(int*)q];
	for(i=0; i<l; i++)
	{
		cmp = pcomp(list1+i, list2+i);
		if(cmp)
		{
			return cmp;
		}
	}
	return 0;
}

int cross(int x1, int x2, int y1, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int n, i, j, k, l, p, q, r;
	while(scanf("%d%d", &px[0], &py[0]) == 2)
	{
		n = 0;
		do
		{
			if(!px[n] && !py[n])
			{
				break;
			}
			index[n] = n;
			n++;
		}while(scanf("%d%d", &px[n], &py[n]) == 2);
		if(!n)
		{
			break;
		}
		qsort(index, n, sizeof(int), pcomp);
		memset(map, 0, sizeof(map));
		for(i=0, k=0; i<n; i++)
		{
			p = index[i];
			for(j=i+1; j<n; j++)
			{
				q = index[j];
				if(!map[p][q])
				{
					for(l=j+1, num[k]=2; l<n; l++)
					{
						r = index[l];
						if(!cross(px[p]-px[q], px[r]-px[q], py[p]-py[q], py[r]-py[q]))
						{
							list[k][num[k]++] = r;
						}
					}
					if(num[k] > 2)
					{
						list[k][0] = p;
						list[k][1] = q;
						for(l=0; l<num[k]; l++)
						{
							for(r=l+1; r<num[k]; r++)
							{
								map[list[k][l]][list[k][r]] = map[list[k][r]][list[k][l]] = 1;
							}
						}
						lindex[k] = k;
						k++;
					}
				}
			}
		}
		if(k)
		{
			qsort(lindex, k, sizeof(int), lcomp);
			printf("The following lines were found:\n");
			for(i=0; i<k; i++)
			{
				for(j=0; j<num[lindex[i]]; j++)
				{
					printf("(%4d,%4d)", px[list[lindex[i]][j]], py[list[lindex[i]][j]]);
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
