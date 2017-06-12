#include <stdio.h>

char map[100][100], n, m;

char valid(int i, int j)
{
	if(i > -1 && i < n && j > -1 && j < m)
	{
		if(map[i][j] == '*')
		{
			return 1;
		}
	}
	return 0;
}

char check(int i, int j)
{
	if(valid(i-1, j))
	{
		return 0;
	}
	if(valid(i-1, j-1))
	{
		return 0;
	}
	if(valid(i, j-1))
	{
		return 0;
	}
	if(valid(i, j+1))
	{
		return 0;
	}
	if(valid(i+1, j))
	{
		return 0;
	}
	if(valid(i+1, j-1))
	{
		return 0;
	}
	if(valid(i+1, j+1))
	{
		return 0;
	}
	if(valid(i-1, j+1))
	{
		return 0;
	}
	return 1;
}

int main()
{
	int i, j, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", &map[i]);
		}
		for(i=0, ans=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '*')
				{
					ans += check(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
