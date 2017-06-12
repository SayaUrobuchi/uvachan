#include <stdio.h>
#include <string.h>

char map[100][100], chk[100];

int main()
{
	int cas, i, j, k, max, n;
	double ans;
	cas = 0;
	while(scanf("%d%d", &i, &j) == 2)
	{
		if(!i && !j)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		memset(chk, 1, sizeof(chk));
		n = 0;
		map[i-1][j-1] = 1;
		if(chk[i-1])
		{
			chk[i-1] = 0;
			n++;
		}
		if(chk[j-1])
		{
			chk[j-1] = 0;
			n++;
		}
		max = i;
		if(j > max)
		{
			max = j;
		}
		while(scanf("%d%d", &i, &j) == 2)
		{
			if(!i && !j)
			{
				break;
			}
			map[i-1][j-1] = 1;
			if(i > max)
			{
				max = i;
			}
			if(j > max)
			{
				max = j;
			}
			if(chk[i-1])
			{
				chk[i-1] = 0;
				n++;
			}
			if(chk[j-1])
			{
				chk[j-1] = 0;
				n++;
			}
		}
		for(k=0; k<max; k++)
		{
			for(i=0; i<max; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<max; j++)
					{
						if(map[k][j])
						{
							if(map[i][k] + map[k][j] < map[i][j] || !map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		ans = 0;
		for(i=0; i<max; i++)
		{
			for(j=0; j<max; j++)
			{
				if(i != j)
				{
					ans += map[i][j];
				}
			}
		}
		ans /= n * (n-1);
		printf("Case %d: average length between pages = %.3f clicks\n", ++cas, ans);
	}
	return 0;
}
