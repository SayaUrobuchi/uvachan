#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int from[305][305], num[305], map[305][305], used[305], queue[305];
char buf[300000];

void printans(int start, int end)
{
	if(start == end)
	{
		printf("%d", start);
		return;
	}
	if(from[start][end])
	{
		printans(start, from[start][end]);
		printf(" %d", end);
	}
	else
	{
		printf("connection impossible");
	}
}

int main()
{
	int n, m, i, j, k, l, now, neigh;
	char *p;
	while(scanf("%d", &n) == 1)
	{
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			scanf("%s", buf);
			sscanf(buf, "%d", &now);
			strtok(buf, "-,");
			while(p=strtok(NULL, "-,"))
			{
				neigh = atoi(p);
				map[now][num[now]++] = neigh;
			}
		}
		memset(from, 0, sizeof(from));
		for(k=1; k<=n; k++)
		{
			memset(used, 0, sizeof(used));
			queue[0] = k;
			used[k] = 1;
			for(i=0, j=1; i<j; i++)
			{
				now = queue[i];
				for(l=0; l<num[now]; l++)
				{
					if(used[map[now][l]] == 0)
					{
						used[map[now][l]] = 1;
						queue[j++] = map[now][l];
						from[k][map[now][l]] = now;
					}
				}
			}
		}
		scanf("%d", &m);
		printf("-----\n");
		while(m--)
		{
			scanf("%d%d", &i, &j);
			printans(i, j);
			printf("\n");
		}
	}
	return 0;
}

