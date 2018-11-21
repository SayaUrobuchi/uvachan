#include <stdio.h>
#include <string.h>

int used[100], adj[100][100], deg[100];

void dfs(int t)
{
	int i;
	used[t] = 1;
	for(i=0; i<26; i++)
	{
		if(adj[t][i] && used[i] == 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	int count, i, n, p, q, f;
	char buf[10005];
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(deg, 0, sizeof(deg));
		memset(adj, 0, sizeof(adj));
		for(i=0; i<n; i++)
		{
			scanf("%s", &buf);
			p = buf[0] - 'a';
			q = buf[strlen(buf)-1] - 'a';
			deg[p]++;
			deg[q]++;
			adj[p][q] = 1;
		}
		memset(used, 0, sizeof(used));
		for(i=0, f=0; i<26; i++)
		{
			f += deg[i] % 2;
		}
		if(f > 2)
		{
			printf("The door cannot be opened.\n");
		}
		else
		{
			for(i=0; i<26; i++)
			{
				if(deg[i])
				{
					dfs(i);
					break;
				}
			}
			for(; i<26; i++)
			{
				if(deg[i] && used[i] == 0)
				{
					break;
				}
			}
			if(i >= 26)
			{
				printf("Ordering is possible.\n");
			}
			else
			{
				printf("The door cannot be opened.\n");
			}
		}
	}
	return 0;
}
