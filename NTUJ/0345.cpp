#include <stdio.h>
#include <string.h>

int map[3005][3005], used[3005], queue[3005], step[3005];

int main()
{
	int count, n, m, i, j, k, s, c, now;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = map[j][i] = 1;
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = 1 - map[i][j];
			map[j][i] = 1 - map[j][i];
		}
		memset(used, 0, sizeof(used));
		used[1] = 1;
		queue[0] = 1;
		step[0] = 0;
		for(i=0, j=1, c=0; i<j; i++)
		{
			now = queue[i];
			s = step[i] + 1;
			if(step[i] > 10)
			{
				c++;
			}
			for(k=1; k<=n; k++)
			{
				if(used[k] == 0 && map[now][k])
				{
					used[k] = 1;
					queue[j] = k;
					step[j++] = s;
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
