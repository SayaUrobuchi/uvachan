#include <stdio.h>

int n, sum, ans, ary[30];

int ab(int num)
{
	return num<0 ? -num : num;
}

void dfs(int depth, int value)
{
	int temp;
	if(depth == n)
	{
		if((temp=ab(sum-value-value)) < ans)
		{
			ans = temp;
		}
		return;
	}
	dfs(depth+1, value);
	dfs(depth+1, value+ary[depth]);
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		ans = 2147483647;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
