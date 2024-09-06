#include <iostream>
#include <algorithm>
using namespace std;

const int N = 16;

int n, m, ans;
char buf[N], str[N];
bool used[N];

bool check(char *s)
{
	int i, j, k;
	for (i=0; i+m<=n; i++)
	{
		for (j=i, k=i+m-1; j<k&&str[j]==str[k]; j++, k--);
		if (j >= k)
		{
			return false;
		}
	}
	return true;
}

void dfs(int depth)
{
	if (depth == n)
	{
		ans += check(str);
		return;
	}
	int i;
	for (i=0; i<n; i++)
	{
		if (!used[i])
		{
			if (i == 0 || used[i-1] || buf[i] != buf[i-1])
			{
				used[i] = true;
				str[depth] = buf[i];
				dfs(depth+1);
				used[i] = false;
			}
		}
	}
}

int main()
{
	scanf("%d%d%s", &n, &m, buf);
	sort(buf, buf+n);
	ans = 0;
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
