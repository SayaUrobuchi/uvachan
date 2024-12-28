#include <stdio.h>
#include <vector>
#include <algorithm>

int st[1048576], ed[1048576], cc[1048576], heap[1048576];
std::vector<int> v[1048576];

int main()
{
	int n, m, i, j, hn, first;
	scanf("%d%d", &n, &m);
	st[0] = 0;
	ed[0] = n+1;
	cc[0] = 0;
	for (i=1; i<=m; i++)
	{
		scanf("%d%d%d", &st[i], &ed[i], &cc[i]);
		v[st[i]].emplace_back(i);
	}
	heap[0] = 0;
	for (i=1, hn=1, first=1; i<=n; i++)
	{
		for (j=0; j<v[i].size(); j++)
		{
			heap[hn] = v[i][j];
			hn++;
			std::push_heap(heap, heap+hn);
		}
		while (hn)
		{
			if (ed[heap[0]] >= i)
			{
				break;
			}
			std::pop_heap(heap, heap+hn);
			hn--;
		}
		if (!first)
		{
			putchar(' ');
		}
		first = 0;
		printf("%d", cc[heap[0]]);
	}
	puts("");
	return 0;
}
