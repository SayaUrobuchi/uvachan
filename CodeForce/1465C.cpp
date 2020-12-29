#include <iostream>
#include <cstring>

int row[131072], column[131072], used[131072];
int px[131072], py[131072];

int main()
{
	int count, n, m, i, j, ans;
	bool xx;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		memset(row, -1, sizeof(row));
		memset(column, -1, sizeof(column));
		memset(used, 0, sizeof(used));
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			row[px[i]] = i;
			column[py[i]] = i;
		}
		for (i=0, ans=0; i<m; i++)
		{
			if (!used[i])
			{
				if (px[i] == py[i])
				{
					continue;
				}
				++ans;
				used[i] = 1;
				for (j=column[px[i]], xx=false; j!=-1&&!used[j]; (xx?j=row[py[j]]:j=column[px[j]]));
				if (j == -1)
				{
					column[py[i]] = -1;
					for (j=column[px[i]], xx=false; j!=-1&&!used[j]; (xx?j=row[py[j]]:j=column[px[j]]))
					{
						used[j] = 1;
						if (xx)
						{
							row[px[j]] = -1;
						}
						else
						{
							column[py[j]] = -1;
						}
						++ans;
					}
				}
				else
				{
					for (j=row[py[i]], xx=true; j!=-1&&!used[j]; (xx?j=row[py[j]]:j=column[px[j]]))
					{
						used[j] = 1;
						if (xx)
						{
							row[px[j]] = -1;
						}
						else
						{
							column[py[j]] = -1;
						}
						++ans;
					}
					if (j != -1)
					{
						++ans;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
