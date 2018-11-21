#include <stdio.h>
#include <string.h>

int c[105], used[105], map[105][105], m;
char cmd[100005], buf[100005], *ptr;

void travel(int now)
{
	int i;
	if(used[now])
	{
		return;
	}
	used[now] = 1;
	for(i=0; i<m; i++)
	{
		if(used[i] == 0 && map[now][i])
		{
			travel(i);
		}
	}
}

int main()
{
	int n, i, j, sum, odd;
	while(gets(cmd))
	{
		if(sscanf(cmd, "%*s%d%d", &n, &m) != 2)
		{
			break;
		}
		memset(c, 0, sizeof(c));
		memset(map, 0, sizeof(map));
		for(i=0, sum=0; i<m; i++)
		{
			gets(buf);
			ptr = strtok(buf, " ");
			if(ptr != NULL)
			{
				do
				{
					sscanf(ptr, "%d", &j);
					c[i]++;
					c[j]++;
					map[i][j] = map[j][i] = 1;
					sum++;
				}while(ptr=strtok(NULL, " "));
			}
		}
		for(i=0, odd=0; i<m; i++)
		{
			odd += c[i] % 2;
		}
		if((odd == 0 && n) || odd > 2 || (odd == 2 && ((c[n] % 2 == 0 && c[0] % 2 == 0) || n == 0)))
		{
			printf("NO\n");
		}
		else
		{
			memset(used, 0, sizeof(used));
			travel(n);
			for(i=0; i<m; i++)
			{
				if(!used[i] && c[i])
				{
					break;
				}
			}
			if(i == m)
			{
				printf("YES %d\n", sum);
			}
			else
			{
				printf("NO\n");
			}
		}
		gets(cmd);
	}
	return 0;
}
