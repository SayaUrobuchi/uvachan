#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int path[32], ary[32];
char buf[128];
vector<string> v;

void dfs(int depth, int res)
{
	int i;
	if (depth == n)
	{
		if (res == m)
		{
			char *p = buf;
			sprintf(p, "%d", path[0]);
			p += strlen(p);
			for (i=1; i<n; i++)
			{
				sprintf(p, "^%d", path[i]);
				p += strlen(p);
			}
			sprintf(p, "=%d", m);
			v.emplace_back(buf);
		}
		return;
	}
	for (i=0; i<=ary[depth]; i++)
	{
		path[depth] = i;
		dfs(depth+1, res^i);
	}
}

int main()
{
	int i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		v.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dfs(0, 0);
		printf("%d\n", v.size());
		for (i=0; i<v.size(); i++)
		{
			puts(v[i].c_str());
		}
	}
	return 0;
}

