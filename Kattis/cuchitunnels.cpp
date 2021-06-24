#include <iostream>

int n, cnt, ary[1024];
bool gg;

void dfs(int cur)
{
	int i;
	++cnt;
	for (i=0; i<ary[cur]; i++)
	{
		if (cnt >= n)
		{
			gg = true;
			return;
		}
		--ary[cnt];
		//printf("cur %d into %d\n", cur, cnt);
		dfs(cnt);
	}
}

int main()
{
	int i, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		gg = false;
		cnt = 0;
		dfs(0);
		puts(gg||cnt!=n?"NO":"YES");
	}
	return 0;
}
