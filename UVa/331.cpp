#include <stdio.h>

int n, ans;
int ary[1001];

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void dfs(int depth)
{
	int i, flag;
	for(i=1, flag=1; i<n; i++)
	{
		if(ary[i] < ary[i-1])
		{
			swap(ary+i, ary+i-1);
			dfs(depth+1);
			swap(ary+i, ary+i-1);
			flag = 0;
		}
	}
	if(depth)
	{
		ans += flag;
	}
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 0;
		dfs(0);
		printf("There are %d swap maps for input data set %d.\n", ans, ++cas);
	}
	return 0;
}
