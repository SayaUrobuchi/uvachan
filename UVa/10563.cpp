#include <stdio.h>

char map[100][81], newchar;
int n, m;

char jdraw(int i, int j)
{
	if(j == -1)
	{
		return 1;
	}
	if(map[i-1][j] != newchar)
	{
		return 1;
	}
	if(map[i][j] == '.')
	{
		return 0;
	}
	if(map[i][j] == '?')
	{
		if(jdraw(i, j-1))
		{
			map[i][j] = newchar;
			return 1;
		}
	}
	return 0;
}

char idraw(int i, int j)
{
	if(i == n)
	{
		return 0;
	}
	if(map[i][j] == '.')
	{
		return 0;
	}
	if(map[i][j-1] == '?')
	{
		if(jdraw(i, j-1))
		{
			map[i][j] = newchar;
			return 1;
		}
	}
	else if(map[i][j-1] == newchar)
	{
		if(idraw(i+1, j))
		{
			map[i][j] = newchar;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	char bline;
	bline = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		if(bline)
		{
			printf("\n");
		}
		bline = 1;
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '?')
				{
					for(newchar = 65; ; newchar++)
					{
						if(!i || map[i-1][j] != newchar)
						{
							if(j == m - 1 || map[i][j+1] != newchar)
							{
								if(j && newchar == map[i][j-1])
								{
									if(!i || map[i-1][j-1] != newchar)
									{
										if(idraw(i+1, j))
										{
											map[i][j] = newchar;
											break;
										}
									}
								}
								else
								{
									map[i][j] = newchar;
									break;
								}
							}
						}
					}
				}
			}
			printf("%s\n", map[i]);
		}
	}
	return 0;
}
