#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[30];
int map[30][30];
char name[30][3];
char s1[3], s2[3];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int bisearch(char *str, int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(str, name[index[center]]);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(str, center+1, right);
	}
	return bisearch(str, left, center-1);
}

int main()
{
	int cas, count, n, m, o, i, j, k, i1, i2;
	cas = 0;
	printf("SHIPPING ROUTES OUTPUT\n\n");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%s%s", s1, s2);
			i1 = bisearch(s1, 0, n-1);
			i2 = bisearch(s2, 0, n-1);
			map[i1][i2] = map[i2][i1] = 1;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(i != j && map[k][j])
						{
							if(!map[i][j] || map[i][k] + map[k][j] < map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		printf("DATA SET  %d\n\n", ++cas);
		while(o--)
		{
			scanf("%d%s%s", &k, s1, s2);
			k *= 100;
			i1 = bisearch(s1, 0, n-1);
			i2 = bisearch(s2, 0, n-1);
			if(map[i1][i2])
			{
				printf("$%d\n", map[i1][i2]*k);
			}
			else
			{
				printf("NO SHIPMENT POSSIBLE\n");
			}
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
