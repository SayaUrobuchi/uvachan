#include <stdio.h>
#include <vector>

int used[1000005];
std::vector<int> v[1000005];

int main()
{
	int n, m, i, p, q, cnt;
	cnt = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		cnt++;
		for(i=0; i<n; i++)
		{
			scanf("%d", &p);
			if(used[p] != cnt)
			{
				v[p].clear();
				used[p] = cnt;
			}
			v[p].push_back(i);
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &q, &p);
			--q;
			if(used[p] == cnt && v[p].size() > q)
			{
				printf("%d\n", v[p][q]+1);
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
