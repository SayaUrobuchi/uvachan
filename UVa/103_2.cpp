#include <stdio.h>
#include <stdlib.h>

int m;
int ary[35][15];
int index[35];
int dp[35];
int from[35];

int cmp(int *a1, int *a2)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(a1[i] < a2[i])
		{
			return -1;
		}
		else if(a1[i] == a2[i])
		{
			return 0;
		}
	}
	return 1;
}

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int comp2(const void *p, const void *q)
{
	return cmp(ary[*(int*)p], ary[*(int*)q]);
}

void backtracing(int now)
{
	if(from[now])
	{
		backtracing(from[now]);
		printf(" ");
	}
	printf("%d", now);
}

int main()
{
	int n, i, j, maxnum, t1, t2, temp;
	for(i=0; i<11; i++)
	{
		ary[0][i] = -2147483640;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
			}
			qsort(ary[i], m, sizeof(int), comp);
			index[i] = i;
		}
		qsort(index+1, n, sizeof(int), comp2);
		for(i=1, maxnum=0; i<=n; i++)
		{
			t1 = index[i];
			/*for(j=0; j<m; j++)
			{
				printf("%4d", ary[t1][j]);
			}
			printf("\n");*/
			for(j=i-1, dp[t1]=-1; j>-1; j--)
			{
				t2 = index[j];
				if(cmp(ary[t1], ary[t2]) > 0 && dp[t2] > dp[t1])
				{
					dp[t1] = dp[t2];
					from[t1] = t2;
				}
			}
			if(maxnum < (dp[t1] += 1))
			{
				maxnum = dp[t1];
				temp = t1;
			}
		}
		printf("%d\n", maxnum);
		backtracing(temp);
		printf("\n");
	}
	return 0;
}
