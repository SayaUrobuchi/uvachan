#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[125];
int map[125][125];
int ary[125];
char name[125][25];
char str[100];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int getindex(int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(name[index[center]], str);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return getindex(left, center-1);
	}
	return getindex(center+1, right);
}

int main()
{
	int count, n, m, i, j, k, c, now;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		memset(map, 0, sizeof(map));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%d", str, &c);
			now = getindex(0, n-1);
			while(c--)
			{
				scanf("%s", str);
				map[now][getindex(0, n-1)] = 1;
			}
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							if(map[i][k] + map[k][j] > map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0, c=0; j<n; j++)
			{
				if(index[i] != j && map[index[i]][j] == 1)
				{
					ary[c++] = j;
				}
			}
			if(c)
			{
				qsort(ary, c, sizeof(int), comp);
				printf("%s %d", name[index[i]], c);
				for(j=0; j<c; j++)
				{
					printf(" %s", name[ary[j]]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
