#include <stdio.h>
#include <stdlib.h>

int ary[1000], ans, way[3000][2], m;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void recursion(int n)
{
	if(n == 3)
	{
		printf("%d\n", ans + ary[0] + ary[1] + ary[2]);
		way[m][0] = ary[0];
		way[m++][1] = ary[2];
		way[m][0] = ary[0];
		way[m++][1] = 0;
		way[m][0] = ary[0];
		way[m++][1] = ary[1];
		return;
	}
	else if(n == 4)
	{
		if(ary[1] + ary[1] < ary[0] + ary[2])
		{
			printf("%d\n", ans + ary[0] + ary[1] + ary[1] + ary[1] + ary[3]);
			way[m][0] = ary[0];
			way[m++][1] = ary[1];
			way[m][0] = ary[0];
			way[m++][1] = 0;
			way[m][0] = ary[2];
			way[m++][1] = ary[3];
			way[m][0] = ary[1];
			way[m++][1] = 0;
			way[m][0] = ary[0];
			way[m++][1] = ary[1];
		}
		else
		{
			printf("%d\n", ans + ary[0] + ary[0] + ary[1] + ary[2] + ary[3]);
			way[m][0] = ary[0];
			way[m++][1] = ary[3];
			way[m][0] = ary[0];
			way[m++][1] = 0;
			way[m][0] = ary[0];
			way[m++][1] = ary[2];
			way[m][0] = ary[0];
			way[m++][1] = 0;
			way[m][0] = ary[0];
			way[m++][1] = ary[1];
		}
		return;
	}
	if(ary[1] + ary[1] < ary[0] + ary[n-2])
	{
		way[m][0] = ary[0];
		way[m++][1] = ary[1];
		way[m][0] = ary[0];
		way[m++][1] = 0;
		way[m][0] = ary[n-1];
		way[m++][1] = ary[n-2];
		way[m][0] = ary[1];
		way[m++][1] = 0;
		ans += ary[0] + ary[1] + ary[1] + ary[n-1];
	}
	else
	{
		way[m][0] = ary[0];
		way[m++][1] = ary[n-1];
		way[m][0] = ary[0];
		way[m++][1] = 0;
		way[m][0] = ary[0];
		way[m++][1] = ary[n-2];
		way[m][0] = ary[0];
		way[m++][1] = 0;
		ans += ary[0] + ary[0] + ary[n-2] + ary[n-1];
	}
	recursion(n-2);
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, 4, comp);
		if(n < 3)
		{
			if(!n)
			{
				printf("0\n");
			}
			else if(n == 1)
			{
				printf("%d\n%d\n", ary[0], ary[0]);
			}
			else
			{
				printf("%d\n%d %d\n", ary[1], ary[0], ary[1]);
			}
		}
		else
		{
			ans = 0;
			m = 0;
			recursion(n);
			for(i=0; i<m; i++)
			{
				if(way[i][1])
				{
					printf("%d %d\n", way[i][0], way[i][1]);
				}
				else
				{
					printf("%d\n", way[i][0]);
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}