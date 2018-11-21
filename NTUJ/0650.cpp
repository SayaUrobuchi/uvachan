#include <stdio.h>

int n, m;
int map[105][105];

int calc(int row, int p, int q)
{
	int i, j, temp;
	if(row < 0)
	{
		return 0;
	}
	for(j=0; j<m; )
	{
		if(j >= p)
		{
			break;
		}
		if(map[row][j])
		{
			j += map[row][j];
		}
		else
		{
			j++;
		}
	}
	for(temp=0, i=j; i<=q; )
	{
		if(map[row][i])
		{
			if(i + map[row][i] - 1 <= q)
			{
				temp += map[row][i];
				i += map[row][i];
			}
			else
			{
				break;
			}
		}
		else
		{
			i++;
		}
	}
	for(; i<m; i++)
	{
		if(map[row][i])
		{
			break;
		}
	}
	for(j--; j>=0; j--)
	{
		if(map[row][j])
		{
			break;
		}
	}
	if(temp)
	{
		return temp + calc(row-1, j+1, i-1);
	}
	return 0;
}

int main()
{
	int i, j, ans, t, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}
		for(i=0, ans=0; i<n; i++)
		{
			for(j=0; j<m; )
			{
				if(map[i][j])
				{
					for(p=j-1; p>=0; p--)
					{
						if(map[i][p])
						{
							break;
						}
					}
					for(q=j+map[i][j]; q<m; q++)
					{
						if(map[i][q])
						{
							break;
						}
					}
					t = calc(i-1, p+1, q-1) + map[i][j];
					if(t > ans)
					{
						ans = t;
					}
					j += map[i][j];
				}
				else
				{
					j++;
					continue;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
