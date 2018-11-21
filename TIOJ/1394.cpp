#include <stdio.h>

int sel[50000], nsel[50000], map[50000][100], num[50000];

int min(int p, int q)
{
	return p<q ? p : q;
}

void recursion(int now)
{
	int i;
	sel[now] = 1;
	nsel[now] = 0;
	for(i=0; i<num[now]; i++)
	{
		recursion(map[now][i]);
		sel[now] += nsel[map[now][i]];
		nsel[now] += sel[map[now][i]];
	}
}

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		recursion(0);
		printf("%d\n", min(sel[0], nsel[0]));
	}
	return 0;
}
