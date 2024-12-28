/*
	ID: sa072682
	LANG: C
	TASK: concom
*/
#include <stdio.h>
#include <string.h>

int map[101][101], con[101], wei[101];

int main()
{
	int m, i, j, k, l;
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d%d", &i, &j, &k);
		map[i][j] = k;
	}
	for(i=1; i<101; i++)
	{
		for(j=1; j<101; j++)
		{
			wei[j] = map[i][j];
		}
		memset(con, 0, sizeof(con));
		for(j=1; j<101; j++)
		{
			for(k=1; k<101; k++)
			{
				if(i != k && !con[k])
				{
					if(wei[k] > 50)
					{
						con[k] = 1;
						for(l=1; l<101; l++)
						{
							wei[l] += map[k][l];
						}
					}
				}
			}
		}
		for(j=1; j<101; j++)
		{
			if(con[j])
			{
				printf("%d %d\n", i, j);
			}
		}
	}
	scanf(" ");
	return 0;
}
