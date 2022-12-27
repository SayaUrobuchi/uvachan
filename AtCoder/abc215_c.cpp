#include <iostream>
#include <algorithm>
using namespace std;

int m, len, cnt;
char buf[128], ans[128];
bool used[128];

void dfs(int depth)
{
	int i, last;
	if (depth == len)
	{
		++cnt;
		return;
	}
	for (i=0, last=0; i<len; i++)
	{
		if (!used[i] && buf[i] != last)
		{
			used[i] = true;
			ans[depth] = buf[i];
			dfs(depth+1);
			used[i] = false;
			if (cnt == m)
			{
				return;
			}
			last = buf[i];
		}
	}
}

int main()
{
	while (scanf("%s", buf) == 1)
	{
		for (len=0; buf[len]; ++len);
		sort(buf, buf+len);
		scanf("%d", &m);
		cnt = 0;
		ans[len] = 0;
		dfs(0);
		puts(ans);
	}
	return 0;
}

