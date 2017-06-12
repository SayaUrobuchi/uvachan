#include <stdio.h>
#include <string.h>

int *st;
int q[105], st1[105], ss[105], st2[105], used[105], pp[105], map[105][105];

void bfs()
{
	int i, j, k, t, s, nex;
	for(i=0, j=1; i<j; i++)
	{
		t = q[i];
		st[t] = ss[i];
		s = ss[i] + 1;
		for(k=0; k<pp[t]; k++)
		{
			nex = map[t][k];
			if(used[nex] == 0)
			{
				used[nex] = 1;
				q[j] = nex;
				ss[j] = s;
				j++;
			}
		}
	}
}

int main()
{
	int cas, count, n, m, i, j, s, t, ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(pp, 0, sizeof(pp));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][pp[i]++] = j;
			map[j][pp[j]++] = i;
		}
		scanf("%d%d", &s, &t);
		st = st1;
		ss[0] = 0;
		q[0] = s;
		memset(used, 0, sizeof(used));
		used[s] = 1;
		bfs();
		st = st2;
		ss[0] = 0;
		q[0] = t;
		memset(used, 0, sizeof(used));
		used[t] = 1;
		bfs();
		for(i=0, ans=0; i<n; i++)
		{
			if(st1[i] + st2[i] > ans)
			{
				ans = st1[i] + st2[i];
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
