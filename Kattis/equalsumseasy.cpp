#include <iostream>
#include <unordered_map>

int n, ans, bns;
int ary[32];
std::unordered_map<int, int> tbl;

void print(int ans)
{
	int i;
	bool first;
	for (i=0, first=true; i<n; i++)
	{
		if (ans & (1<<i))
		{
			if (!first)
			{
				putchar(' ');
			}
			first = false;
			printf("%d", ary[i]);
		}
	}
	puts("");
}

void dfs(int depth, int stat, int sum)
{
	if (stat)
	{
		if (tbl[sum] && tbl[sum] != stat)
		{
			ans = stat;
			bns = tbl[sum];
			//printf("!? %d %d %d\n", ans, bns, sum);
			stat = (ans & bns);
			ans &= ~stat;
			bns &= ~stat;
			return;
		}
		tbl[sum] = stat;
	}
	if (depth == 20)
	{
		return;
	}
	dfs(depth+1, stat, sum);
	if (ans != -1)
	{
		return;
	}
	dfs(depth+1, stat|(1<<depth), sum+ary[depth]);
}

int main()
{
	int count, cas, i;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		tbl.clear();
		ans = -1;
		dfs(0, 0, 0);
		printf("Case #%d:\n", ++cas);
		if (ans == -1)
		{
			puts("Impossible");
		}
		else
		{
			print(ans);
			print(bns);
		}
	}
	return 0;
}