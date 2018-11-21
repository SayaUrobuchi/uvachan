#include <stdio.h>
#include <stdlib.h>

int map[105][105], list[10505][3];

int comp(const void *p, const void *q)
{
	if(*(int*)p != *(int*)q)
	{
		return *(int*)p - *(int*)q;
	}
	if(*(((int*)p)+1) != *(((int*)q)+1))
	{
		return *(((int*)p)+1) - *(((int*)q)+1);
	}
	return *(((int*)p)+2) - *(((int*)q)+2);
}

int main()
{
	int n, m, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i=0, m=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				for(k=j+1; k<n; k++)
				{
					if(!map[i][j] && !map[i][k] && !map[j][k] && !map[j][i] && !map[k][i] && !map[k][j])
					{
						list[m][0] = i;
						list[m][1] = j;
						list[m][2] = k;
						m++;
					}
					else if(map[i][j] && map[j][k] && map[k][i])
					{
						list[m][0] = i;
						list[m][1] = j;
						list[m][2] = k;
						m++;
					}
					else if(map[j][i] && map[i][k] && map[k][j])
					{
						list[m][0] = k;
						list[m][1] = j;
						list[m][2] = i;
						m++;
					}
				}
			}
		}
		qsort(list, m, sizeof(list[0]), comp);
		printf("%d\n", m);
		for(i=0; i<m; i++)
		{
			printf("%d %d %d\n", list[i][0]+1, list[i][1]+1, list[i][2]+1);
		}
	}
	return 0;
}
