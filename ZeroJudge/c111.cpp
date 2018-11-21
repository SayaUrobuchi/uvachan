#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[100][100], num[100], chk[100], str[10000], *ptr, count;

void dfs(int now)
{
	int i, j;
	for(i=0, j=num[now]; i<j; i++)
	{
		if(chk[map[now][i]])
		{
			chk[map[now][i]] = 0;
			count++;
			dfs(map[now][i]);
		}
	}
}

int main()
{
	int n, m, i, temp, ans;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		while(scanf("%d", &m) == 1)
		{
			if(!m)
			{
				break;
			}
			m--;
			gets(str);
			ptr = strtok(str, " ");
			do
			{
				temp = atoi(ptr)-1;
				map[m][num[m]++] = temp;
				map[temp][num[temp]++] = m;
			}while(ptr = strtok(NULL, " "));
		}
		ans = 0;
		memset(chk, 1, sizeof(chk));
		count = 2;
		chk[0] = 0;
		chk[1] = 0;
		dfs(1);
		if(count != n)
		{
			ans++;
		}
		for(i=1; i<n; i++)
		{
			memset(chk, 1, sizeof(chk));
			count = 2;
			chk[i] = 0;
			chk[0] = 0;
			dfs(0);
			if(count != n)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
