#include <stdio.h>
#include <string.h>

char map[101][101];
int count[101];

int main()
{
	int n, m, o, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		memset(map, 0, sizeof(map));
		if(!n) break;
		while(scanf("%d", &m) == 1)
		{
			if(!m) break;
			while(scanf("%d", &o) == 1)
			{
				if(!o) break;
				map[m][o] = 1;
			}
		}
		for(k=1, n++; k<n; k++)
		{
			for(i=1; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=1; j<n; j++)
					{
						if(map[k][j]) map[i][j] = 1;
					}
				}
			}
		}
		for(i=1; i<n; i++)
		{
			for(j=1, count[i]=n-1; j<n; j++)
			{
				count[i] -= map[i][j];
			}
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &o);
			printf("%d", count[o]);
			for(i=1; i<n; i++)
			{
				if(!map[o][i])
				{
					printf(" %d", i);
				}
			}
			puts("");
		}
	}
	return 0;
}
