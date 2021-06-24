#include <iostream>
#include <algorithm>

int n, ans;
int ucnt, used[16], appear[10000005];
int tbl[10000005];
char s[1024];

void dfs(int depth, int val)
{
	int i, t, last;
	if (appear[val] != ucnt)
	{
		appear[val] = ucnt;
		if (!tbl[val])
		{
			++ans;
		}
	}
	if (depth == n)
	{
		return;
	}
	for (i=0, last=-1; i<n; i++)
	{
		if (used[i] != ucnt)
		{
			t = s[i] - '0';
			if (t != last)
			{
				used[i] = ucnt;
				dfs(depth+1, val*10+t);
				used[i] = 0;
			}
		}
	}
}

int main()
{
	int count, i, j;
	tbl[0] = tbl[1] = 1;
	for (i=2; i*i<=9999999; i++)
	{
		if (!tbl[i])
		{
			for (j=i*i; j<=9999999; j+=i)
			{
				tbl[j] = i;
			}
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (n=0; s[n]; n++);
		std::sort(s, s+n);
		ans = 0;
		++ucnt;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
