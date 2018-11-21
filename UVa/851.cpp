#include <stdio.h>
#include <string.h>

#define GOING 1
#define DEAD 2
#define SUCC 3

int id, n, ln, fn, state;
int used[10][10], res[1000], listx[100], listy[100], fact[1000];
int xd[] = {0, 1, 0, -1}, yd[] = {1, 0, -1, 0};
char map[10][10];

int can_move(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n && map[x][y] == '.';
}

void move(int dir, int *p, int *q)
{
	int x, y;
	x = *p + xd[dir];
	y = *q + yd[dir];
	if(can_move(x, y))
	{
		*p = x;
		*q = y;
	}
}

int go(int p, int q)
{
	int i;
	if(used[p][q] == GOING)
	{
		used[p][q] = DEAD;
	}
	if(used[p][q])
	{
		return used[p][q];
	}
	if(p == 0 || p == n-1 || q == 0 || q == n-1)
	{
		return 1;
	}
	used[p][q] = GOING;
	while(1)
	{
		for(i=0; i<id; i++)
		{
			move(res[i], &p, &q);
			if(p == 0 || p == n-1 || q == 0 || q == n-1)
			{
				return used[p][q] = SUCC;
			}
		}
		return used[p][q]=go(p, q);
	}
}

int check_repeat()
{
	int i, j, k;
	for(i=0; i<fn; i++)
	{
		for(j=0; j<fact[i]; j++)
		{
			for(k=j+fact[i]; k<id; k+=fact[i])
			{
				if(res[k] != res[j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int check_ans()
{
	int i, j, x, y;
	/*for(i=1; i<n-1; i++)
	{
		for(j=1; j<n-1; j++)
		{
			if(map[i][j] == '.')
			{
				if(!go(i, j))
				{
					return 0;
				}
			}
		}
	}*/
	if(check_repeat())
	{
		return 0;
	}
	memset(used, 0, sizeof(used));
	for(i=0; i<ln; i++)
	{
		x = listx[i];
		y = listy[i];
		if(map[x][y] == '.')
		{
			if(go(x, y) != SUCC)
			{
				return 0;
			}
		}
	}
	return 1;
}

int idfs(int depth, int stat)
{
	int i;
	if(depth == id)
	{
		return (stat&state) && check_ans();
	}
	for(i=0; i<4; i++)
	{
		res[depth] = i;
		if(idfs(depth+1, stat|(1<<i)))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		state = 0;
		for(i=1, ln=0; i<n-1; i++)
		{
			for(j=1; j<n-1; j++)
			{
				if(map[i][j] == '.')
				{
					listx[ln] = i;
					listy[ln] = j;
					ln++;
					for(k=0; k<4; k++)
					{
						if(can_move(i+xd[k], j+xd[k]))
						{
							state |= (1 << k);
						}
					}
				}
			}
		}
		for(id=1; ; id++)
		{
			for(i=1, fn=0; i<id; i++)
			{
				if(id % i == 0)
				{
					fact[fn++] = i;
				}
			}
			if(idfs(0, 0))
			{
				for(i=0; i<id; i++)
				{
					if(res[i] == 0)
					{
						printf("east\n");
					}
					else if(res[i] == 1)
					{
						printf("south\n");
					}
					else if(res[i] == 2)
					{
						printf("west\n");
					}
					else
					{
						printf("north\n");
					}
				}
				break;
			}
		}
	}
	return 0;
}
