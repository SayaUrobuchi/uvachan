#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v[16384], path;

void dfs(int depth, int sum, int add)
{
	if (depth == 0)
	{
		v[sum] = path;
		return;
	}
	if (add && add % depth == 0)
	{
		path[depth-1] = 0;
		dfs(depth-1, sum, add+add/depth);
	}
	path[depth-1] = depth-add%depth;
	dfs(depth-1, sum+path[depth-1], add+add/depth+1);
}

int main()
{
	int cas, count, n, i;
	for (i=1; i<=80; i++)
	{
		path.resize(i);
		dfs(i, 0, 0);
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		printf("%d %d\n", cas, v[n].size());
		for (i=0; i<v[n].size(); i++)
		{
			if (i%10 == 0)
			{
				printf("%s%d", i?"\n":"", v[n][i]);
			}
			else
			{
				printf(" %d", v[n][i]);
			}
		}
		puts("");
	}
	return 0;
}
