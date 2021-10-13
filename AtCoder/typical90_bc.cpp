#include <iostream>
using namespace std;

int n, p, q, ans;
int ary[128];

void dfs(int depth, int cur, int st)
{
	int i;
	if (depth == 5)
	{
		if (cur == q)
		{
			++ans;
		}
		return;
	}
	for (i=st; i+(5-depth-1)<n; i++)
	{
		dfs(depth+1, cur*(long long)ary[i]%p, i+1);
	}
}

int main()
{
	int i;
	while (scanf("%d%d%d", &n, &p, &q) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 0;
		dfs(0, 1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
