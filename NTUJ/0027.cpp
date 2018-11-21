#include <stdio.h>
#include <string.h>

int row[105], column[105];
char map[105][105];

int main()
{
	int count, n, m, i, j, f, w, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '1')
				{
					row[i]++;
					column[j]++;
				}
			}
		}
		ans = 0;
		for(i=0; i<n; i++)
		{
			if(row[i] != 0 && row[i] < 3)
			{
				for(; row[i] < 3; row[i]++)
				{
					for(j=0, f=0; j<m; j++)
					{
						if(map[i][j] == '0')
						{
							if(column[j] == 0)
							{
								if(f == 0)
								{
									w = j;
								}
							}
							else if(column[j] >= 3)
							{
								if(f == 0)
								{
									f = 1;
									w = j;
								}
							}
							else
							{
								if(f < 4 - column[j])
								{
									f = 4 - column[j];
									w = j;
								}
							}
						}
					}
					ans++;
					column[w]++;
					map[i][w] = '2';
				}
			}
		}
		for(i=0; i<m; i++)
		{
			if(column[i] != 0 && column[i] < 3)
			{
				for(; column[i] < 3; column[i]++)
				{
					for(j=0, f=0; j<n; j++)
					{
						if(map[j][i] == '0')
						{
							if(row[j] == 0)
							{
								if(f == 0)
								{
									w = j;
								}
							}
							else if(row[j] >= 3)
							{
								if(f == 0)
								{
									f = 1;
									w = j;
								}
							}
							else
							{
								if(f < 4 - row[j])
								{
									f = 4 - row[j];
									w = j;
								}
							}
						}
					}
					ans++;
					row[w]++;
					map[w][i] = '2';
				}
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '2')
				{
					if(row[i] > 3 && column[j] > 3)
					{
						map[i][j] = '0';
						row[i]--;
						column[j]--;
						ans--;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
