#include <stdio.h>
#include <string.h>

int used[10005], sel[10005], nsel[10005], nsp[10005], num[10005], map[10005][100];

int min(int p, int q)
{
	return p<q ? p : q;
}

void recursion(int now)
{
	int i, temp;
	used[now] = 1;
	sel[now] = 1;
	nsel[now] = 0;
	nsp[now] = 0;
	for(i=0, temp=210000; i<num[now]; i++)
	{
		if(used[map[now][i]] == 0)
		{
			recursion(map[now][i]);
			sel[now] += min(nsel[map[now][i]], min(nsp[map[now][i]], sel[map[now][i]]));
			nsel[now] += min(sel[map[now][i]], nsel[map[now][i]]);
			temp = min(temp, sel[map[now][i]]-nsel[map[now][i]]);
			nsp[now] += nsel[map[now][i]];
		}
	}
	if(temp < 0)
	{
		temp = 0;
	}
	nsel[now] += temp;
}

int main()
{
	int n, i, p, q;
	while(scanf("%d", &n) == 1)
	{
		memset(used, 0, sizeof(used));
		memset(num, 0, sizeof(num));
		for(i=1; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			if(num[p] >= 100 || num[q] >= 100)
			{
				for(; ; );
			}
			map[p][num[p]++] = q;
			map[q][num[q]++] = p;
		}
		recursion(1);
		printf("%d\n", min(sel[1], nsel[1]));
	}
	return 0;
}
