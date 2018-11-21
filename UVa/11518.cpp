#include <stdio.h>
#include <vector>

int u[10005], w[10005];
std::vector<int> v[10005];
int n, cas;

void dfs(int a)
{
	int i, j;
	if(w[a] == cas)
	{
		return;
	}
	w[a] = cas;
	n++;
	if(u[a] != cas)
	{
		return;
	}
	for(i=0, j=v[a].size(); i<j; i++)
	{
		dfs(v[a][i]);
	}
}

int main()
{
	int count, m, o, a, b;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		++cas;
		scanf("%d%d%d", &n, &m, &o);
		while(m--)
		{
			scanf("%d%d", &a, &b);
			if(u[a] != cas)
			{
				u[a] = cas;
				v[a].clear();
			}
			v[a].push_back(b);
		}
		n = 0;
		while(o--)
		{
			scanf("%d", &a);
			dfs(a);
		}
		printf("%d\n", n);
	}
	return 0;
}
