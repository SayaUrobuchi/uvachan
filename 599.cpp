#include <stdio.h>
#include <string.h>

char map[26][27], check[26], buf[1000], tree, acorn;

void dfs(int now)
{
	int i, lim;
	lim = map[now][0];
	for(i=1; i<lim; i++)
	{
		if(check[map[now][i]])
		{
			check[map[now][i]] = 0;
			dfs(map[now][i]);
		}
	}
}

int main()
{
	int count, i, j, len;
	scanf("%d", &count);
	while(count--)
	{
		memset(check, 1, sizeof(check));
		for(i=0; i<26; i++)
		{
			map[i][0] = 1;
		}
		while(scanf("%s", buf) == 1)
		{
			if(buf[0] == '*')
			{
				break;
			}
			i = buf[1] - 65;
			j = buf[3] - 65;
			map[i][map[i][0]++] = j;
			map[j][map[j][0]++] = i;
		}
		scanf("%s", buf);
		len = strlen(buf);
		tree = 0;
		acorn = 0;
		for(i=0; i<len; i+=2)
		{
			j = buf[i] - 65;
			if(check[j])
			{
				if(map[j][0] == 1)
				{
					acorn++;
				}
				else
				{
					check[j] = 0;
					dfs(j);
					tree++;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
	return 0;
}