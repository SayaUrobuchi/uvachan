#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int mnum[1005], map[1005][1005];
int used[1005], mat[1005];
char buf[1000005];

int match(int t);

int rev(int t)
{
	if(used[t+n])
	{
		return 0;
	}
	used[t+n] = 1;
	if(mat[t] == -1)
	{
		return 1;
	}
	return match(mat[t]);
}

int match(int t)
{
	int i;
	if(used[t])
	{
		return 0;
	}
	used[t] = 1;
	for(i=0; i<mnum[t]; i++)
	{
		if(rev(map[t][i]))
		{
			mat[map[t][i]] = t;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int m, i, ans;
	char *ptr;
	while(scanf("%d%d", &n, &m) == 2)
	{
		gets(buf);
		memset(mat, -1, sizeof(mat));
		for(i=0, ans=0; i<n; i++)
		{
			memset(used, 0, sizeof(used));
			gets(buf);
			mnum[i] = 0;
			ptr = strtok(buf, " ");
			if(ptr)
			{
				do
				{
					map[i][mnum[i]++] = atoi(ptr);
				}while(ptr=strtok(NULL, " "));
			}
			ans += match(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
