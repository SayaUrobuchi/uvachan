#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
double ans;
double ary[8];
double dis[8];
double loc[8];
int list[8];
int chk[8];

void dfs(int depth)
{
	int i, j;
	double sum, sub, temp, left, right;
	if(depth == n)
	{
		loc[0] = 0;
		for(i=1; i<n; i++)
		{
			loc[i] = 0;
			for(j=0; j<i; j++)
			{
				sum = ary[list[i]] + ary[list[j]];
				sum *= sum;
				sub = ary[list[i]] - ary[list[j]];
				sub *= sub;
				temp = sqrt(sum-sub);
				if(temp + loc[j] > loc[i])
				{
					loc[i] = temp + loc[j];
				}
			}
		}
		for(i=0, left=1e10, right=-1e10; i<n; i++)
		{
			if(loc[i] - ary[list[i]] < left)
			{
				left = loc[i] - ary[list[i]];
			}
			if(loc[i] + ary[list[i]] > right)
			{
				right = loc[i] + ary[list[i]];
			}
		}
		if(right-left < ans || ans < 0)
		{
			ans = right - left;
		}
		return;
	}
	for(i=0; i<n; i++)
	{
		if(!chk[i])
		{
			chk[i] = 1;
			list[depth] = i;
			dfs(depth+1);
			chk[i] = 0;
		}
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf", &ary[i]);
		}
		memset(chk, 0, sizeof(chk));
		ans = -1;
		dfs(0);
		printf("%.3lf\n", ans);
	}
	return 0;
}
