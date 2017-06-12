#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 8

int aryx[N*N], aryy[N*N];
int index[N*N];
int row[N], column[N];
int diago1[N+N], diago2[N+N];
int wayx[8] = {0, 1, -1, 1, 0, -1, 1, -1};
int wayy[8] = {1, 0, 1, 1, -1, 0, -1, -1};
char map[N][N+1];
char buf[1001];
char buf1[1001], buf2[1001];

int comp(const void *p, const void *q)
{
	if(aryx[*(int*)p] == aryx[*(int*)q])
	{
		return aryy[*(int*)p] - aryy[*(int*)q];
	}
	return aryx[*(int*)p] - aryx[*(int*)q];
}

int valid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int getnextstep(int x, int y, int type)
{
	type %= 4;
	if(!type)
	{
		return row[x];
	}
	else if(type == 1)
	{
		return column[y];
	}
	else if(type == 2)
	{
		return diago1[x+y];
	}
	return diago2[x-y+N];
}

char *deal(int x, int y, char *s)
{
	sprintf(s, "%c%d", x+'A', y+1);
	return s;
}

int main()
{
	int cas, i, j, k, l, x, y, chess, ans, nextstep;
	cas = 0;
	for(; ; )
	{
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(diago1, 0, sizeof(diago1));
		memset(diago2, 0, sizeof(diago2));
		for(i=0; i<N; i++)
		{
			if(!gets(map[i]))
			{
				break;
			}
			for(j=0; j<N; j++)
			{
				if(map[i][j] != '.')
				{
					row[i]++;
					column[j]++;
					diago1[i+j]++;
					diago2[i-j+N]++;
				}
			}
		}
		if(i < N)
		{
			break;
		}
		gets(buf);
		chess = buf[0];
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0, ans=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(map[i][j] == chess)
				{
					for(k=0, l=0; k<8; k++)
					{
						nextstep = getnextstep(i, j, k);
						for(x=i+wayx[k], y=j+wayy[k]; valid(x, y); x+=wayx[k], y+=wayy[k])
						{
							if(map[x][y] == '.' || map[x][y] == chess)
							{
								nextstep--;
								if(!nextstep)
								{
									break;
								}
							}
							else
							{
								nextstep--;
								break;
							}
						}
						if(!nextstep && valid(x, y) && map[x][y] != chess)
						{
							index[l] = l;
							aryx[l] = x;
							aryy[l++] = y;
						}
					}
					qsort(index, l, sizeof(int), comp);
					ans += l;
					for(k=0; k<l; k++)
					{
						printf("%s-%s\n", deal(i, j, buf1), deal(aryx[index[k]], aryy[index[k]], buf2));
					}
				}
			}
		}
		if(!ans)
		{
			printf("No moves are possible\n");
		}
	}
	return 0;
}
