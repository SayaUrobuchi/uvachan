#include <stdio.h>
#include <string.h>

int from[150], queue[150], type[150], ch[150][2], used[150];
char story[150][300], s[1500], ending[150][100];

void backtracking(int now)
{
	if(from[now] != -1)
	{
		backtracking(from[now]);
	}
	puts(story[queue[now]]);
}

int main()
{
	int cas, count, n, i, j, k, now, next;
	char *st, *en;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(s);
		for(i=1; i<=n; i++)
		{
			gets(s);
			type[i] = s[0];
			strtok(s, "\"");
			st = strtok(NULL, "\"");
			en = strtok(NULL, "\"");
			strcpy(story[i], st);
			if(type[i] == 'C')
			{
				sscanf(en, "%d%d", &ch[i][0], &ch[i][1]);
			}
			else
			{
				sscanf(en, "%s", ending[i]);
			}
		}
		queue[0] = 1;
		memset(used, 0, sizeof(used));
		used[1] = 1;
		from[0] = -1;
		for(i=0, j=1; i<j; i++)
		{
			now = queue[i];
			if(type[now] == 'C')
			{
				for(k=0; k<2; k++)
				{
					next = ch[now][k];
					if(used[next] == 0)
					{
						used[next] = 1;
						queue[j] = next;
						from[j++] = i;
						if(type[next] == 'E' && strcmp(ending[next], "HAPPY") == 0)
						{
							break;
						}
					}
				}
				if(k < 2)
				{
					break;
				}
			}
		}
		printf("STORY %d\n", ++cas);
		backtracking(j-1);
	}
	return 0;
}
