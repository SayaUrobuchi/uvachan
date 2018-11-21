#include <stdio.h>
#include <string.h>

int tbl[128];
char map[100][100];

int main()
{
	int cas, count, n, m, p, q, i, j, mx, ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &n, &m, &p, &q);
		memset(tbl, 0, sizeof(tbl));
		mx = 0;
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<m; j++)
			{
				tbl[map[i][j]]++;
				if(tbl[map[i][j]] > mx)
				{
					mx = tbl[map[i][j]];
				}
			}
		}
		for(i='A', ans=0; i<='Z'; i++)
		{
			if(tbl[i] == mx)
			{
				ans += tbl[i] * p;
			}
			else
			{
				ans += tbl[i] * q;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
