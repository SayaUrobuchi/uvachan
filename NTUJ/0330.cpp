#include <stdio.h>

int n, ans;
char ary[105][20], list[20];

int max(int p, int q)
{
	return p > q ? p : q;
}

void chk()
{
	int i, j, k;
	char *p;
	for(i=1; i<n; i++)
	{
		for(j=0, k=0, p=ary[i]; p[j]&&list[k]; j++)
		{
			if(list[k] == p[j])
			{
				k++;
			}
		}
		if(list[k])
		{
			break;
		}
	}
	if(i == n)
	{
		if(k > ans)
		{
			ans = k;
		}
	}
}

void dfs(int depth, int len)
{
	if(ary[0][depth] == 0)
	{
		list[len] = 0;
		if(len > ans)
		{
			chk();
		}
		return;
	}
	dfs(depth+1, len);
	list[len] = ary[0][depth];
	dfs(depth+1, len+1);
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
		}
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
