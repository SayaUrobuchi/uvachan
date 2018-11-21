#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, len;
char map[1000][1000];
int dis[1000][1000];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char str[5000];

struct node
{
	int x, y;
	struct node *next;
};

struct node *list[10], *last[10];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int main()
{
	int count, i, j, k, v, x, y, tx, ty;
	struct node *ptr, *temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		gets(str);
		for(i=0; i<n; i++)
		{
			gets(str);
			for(j=0, k=0; j<m; j++, k+=2)
			{
				map[i][j] = str[k] - 48;
				dis[i][j] = 0;
			}
		}
		if(n == 1 && m == 1)
		{
			printf("%d\n", map[0][0]);
		}
		else
		{
			dis[0][0] = map[0][0] + 1;
			for(i=0; i<10; i++)
			{
				list[i] = last[i] = NULL;
			}
			i = dis[0][0] % 10;
			list[i] = (struct node*)malloc(sizeof(struct node));
			list[i]->x = list[i]->y = 0;
			list[i]->next = NULL;
			last[i] = list[i];
			for(; ; i++)
			{
				if(i == 10)
				{
					i = 0;
				}
				for(ptr=list[i]; ptr; temp=ptr, ptr=ptr->next, free(temp))
				{
					x = ptr->x;
					y = ptr->y;
					for(k=0; k<4; k++)
					{
						tx = x + wayx[k];
						ty = y + wayy[k];
						if(valid(tx, ty) && !dis[tx][ty])
						{
							dis[tx][ty] = dis[x][y] + map[tx][ty];
							if(tx == n-1 && ty == m-1)
							{
								break;
							}
							v = dis[tx][ty] % 10;
							temp = (struct node*)malloc(sizeof(struct node));
							temp->x = tx;
							temp->y = ty;
							temp->next = NULL;
							if(last[v])
							{
								last[v]->next = temp;
								last[v] = temp;
							}
							else
							{
								list[v] = last[v] = temp;
							}
						}
					}
					if(k < 4)
					{
						break;
					}
				}
				if(ptr)
				{
					break;
				}
				list[i] = NULL;
				last[i] = NULL;
			}
			printf("%d\n", dis[tx][ty]-1);
		}
	}
	return 0;
}
