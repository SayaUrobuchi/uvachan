#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;
int board[25][25];
int list[200][4];
int aryx[128][400], aryy[128][400];
int num[128];
char map[25][25];

int dfs(int depth, int remains)
{
	int i, j, k, l, s, x, y, check, ch;
	char mark[25][25];
	if(!remains)
	{
		for(i=0; i<depth; i++)
		{
			printf("(%d,%d),(%d,%d)\n", list[i][0], list[i][1], list[i][2], list[i][3]);
		}
		return 1;
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(map[i][j])
			{
				ch = map[i][j];
				map[i][j] = 0;
				list[depth][0] = j;
				list[depth][1] = i;
				memset(mark, 0, sizeof(mark));
				for(k=i-1; k>-1; k--)
				{
					if(map[k][j])
					{
						break;
					}
					for(l=j; l>-1; l--)
					{
						if(map[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
					for(l=j+1; l<=m+1; l++)
					{
						if(map[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
				}
				for(k=i+1; k<=n+1; k++)
				{
					if(map[k][j])
					{
						break;
					}
					for(l=j; l>-1; l--)
					{
						if(map[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
					for(l=j+1; l<=m+1; l++)
					{
						if(map[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
				}
				for(k=j-1; k>-1; k--)
				{
					if(map[i][k])
					{
						break;
					}
					for(l=i; l>-1; l--)
					{
						if(map[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
					for(l=i+1; l<=n+1; l++)
					{
						if(map[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
				}
				for(k=j+1; k<=m+1; k++)
				{
					if(map[i][k])
					{
						break;
					}
					for(l=i; l>-1; l--)
					{
						if(map[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
					for(l=i+1; l<=n+1; l++)
					{
						if(map[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
				}
				for(s=board[i][j]+1; s<num[ch]; s++)
				{
					x = aryx[ch][s];
					y = aryy[ch][s];
					if(map[x][y])
					{
						check = 0;
						for(k=x-1; k>-1; k--)
						{
							if(mark[k][y])
							{
								check = 1;
								break;
							}
							if(map[k][y])
							{
								break;
							}
						}
						if(!check)
						{
							for(k=x+1; k<=n+1; k++)
							{
								if(mark[k][y])
								{
									check = 1;
									break;
								}
								if(map[k][y])
								{
									break;
								}
							}
							if(!check)
							{
								for(k=y-1; k>-1; k--)
								{
									if(mark[x][k])
									{
										check = 1;
										break;
									}
									if(map[x][k])
									{
										break;
									}
								}
								if(!check)
								{
									for(k=y+1; k<=m+1; k++)
									{
										if(mark[x][k])
										{
											check = 1;
											break;
										}
										if(map[x][k])
										{
											break;
										}
									}
								}
							}
						}
						if(check)
						{
							map[x][y] = 0;
							list[depth][2] = y;
							list[depth][3] = x;
							if(dfs(depth+1, remains-2))
							{
								return 1;
							}
							map[x][y] = ch;
						}
					}
				}
				map[i][j] = ch;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, temp;
	while(scanf("%d%d", &m, &n) == 2)
	{
		memset(num, 0, sizeof(num));
		for(i=1; i<=n; i++)
		{
			scanf("%s", map[i]+1);
			for(j=1; j<=m; j++)
			{
				temp = map[i][j];
				aryx[temp][num[temp]] = i;
				aryy[temp][num[temp]] = j;
				board[i][j] = num[temp]++;
			}
		}
		for(i=0; i<128; i++)
		{
			if(num[i] % 2)
			{
				break;
			}
		}
		if(i < 128)
		{
			printf("No solution\n");
		}
		else if(!dfs(0, n*m))
		{
			printf("No solution\n");
		}
	}
	return 0;
}
