#include <iostream>
#include <unordered_set>
using us = std::unordered_set<int>;

int n;
us tbl;
long long ary[128];

void dfs(int depth, long long sum)
{
	int i;
	char buf[32], *p;
	long long t;
	if (depth == n)
	{
		tbl.insert(sum);
		return;
	}
	for (i=depth, p=buf; i<n; i++)
	{
		p += sprintf(p, "%lld", ary[i]);
		sscanf(buf, "%lld", &t);
		dfs(i+1, sum+t);
	}
}

int main()
{
	int i, t;
	char s[1024], *p;
	while (scanf("%s", s) == 1)
	{
		for (i=0, p=s; *p; i++)
		{
			sscanf(p, "%lld%n", &ary[i], &t);
			p += t;
			if (*p)
			{
				++p;
			}
		}
		n = i;
		tbl.clear();
		dfs(0, 0);
		printf("%d\n", tbl.size());
	}
	return 0;
}
