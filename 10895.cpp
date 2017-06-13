#include <stdio.h>
#include <string.h>

int pn[10005], idx[10005][1005], val[10005][1005], temp[1005];

int main()
{
	int n, m, i, j, r;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(pn, 0, sizeof(pn));
		for (i=1; i<=n; i++)
		{
			scanf("%d", &r);
			for (j=0; j<r; j++)
			{
				scanf("%d", &temp[j]);
				idx[temp[j]][pn[temp[j]]] = i;
			}
			for (j=0; j<r; j++)
			{
				scanf("%d", &val[temp[j]][pn[temp[j]]++]);
			}
		}
		printf("%d %d\n", m, n);
		for (i=1; i<=m; i++)
		{
			printf("%d", pn[i]);
			for (j=0; j<pn[i]; j++)
			{
				printf(" %d", idx[i][j]);
			}
			printf("\n");
			for (j=0; j<pn[i]; j++)
			{
				printf(j?" %d":"%d", val[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
