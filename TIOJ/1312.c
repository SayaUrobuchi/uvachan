#include <stdio.h>
#include <string.h>

int parent[10005];

int find(int now)
{
	return parent[now] ? parent[now]=find(parent[now]) : now;
}

int main()
{
	int n, m, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(parent, 0, sizeof(parent));
		while(m--)
		{
			scanf("%d%d", &p, &q);
			p = find(p), q = find(q);
			p != q ? (p < q ? parent[q] = p : parent[p] = q) : 0;
		}
		scanf("%d", &m), printf("%d\n", find(m));
	}
	return 0;
}
