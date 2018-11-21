#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char stat[17];
};

char init[17], ans[46], lim, next, direct[4] = {'U', 'L', 'D', 'R'}, way[4] = {-4, -1, 4, 1};
data head;

int dis(int n, int loc)
{
	int i, j;
	n--;
	i = n / 4 - loc / 4;
	if(i < 0)
	{
		i = -i;
	}
	j = n % 4 - loc % 4;
	if(j < 0)
	{
		j = -j;
	}
	return i + j;
}

int idfs(data now, int depth, char dir, int loc, int stat)
{
	data tmp[4];
	char nstat[4], sort[4], i, tmp2;
	memset(sort, 0, sizeof(sort));
	if(stat > lim - depth)
	{
		if(stat - lim + depth < next)
		{
			next = stat - lim + depth;
		}
		return 0;
	}
	if(!stat)
	{
		ans[depth] = 0;
		return 1;
	}
	if(loc > 3 && dir != 'D')
	{
		tmp[0] = now;
		tmp[0].stat[loc] = now.stat[loc-4];
		tmp[0].stat[loc-4] = now.stat[loc];
		if((loc-4) / 4 < (now.stat[loc-4]-1) / 4)
		{
			nstat[0] = stat - 1;
			sort[0] = 1;
		}
		else
		{
			nstat[0] = stat + 1;
			sort[3] = 1;
		}
	}
	if(loc % 4 && dir != 'R')
	{
		tmp[1] = now;
		tmp[1].stat[loc] = now.stat[loc-1];
		tmp[1].stat[loc-1] = now.stat[loc];
		if((loc-1) % 4 < (now.stat[loc-1]-1) % 4)
		{
			nstat[1] = stat - 1;
			for(i=0; i<4; i++)
			{
				if(!sort[i])
				{
					sort[i] = 2;
					break;
				}
			}
		}
		else
		{
			nstat[1] = stat + 1;
			for(i=3; i>-1; i--)
			{
				if(!sort[i])
				{
					sort[i] = 2;
					break;
				}
			}
		}
	}
	if(loc < 12 && dir != 'U')
	{
		tmp[2] = now;
		tmp[2].stat[loc] = now.stat[loc+4];
		tmp[2].stat[loc+4] = now.stat[loc];
		if((loc+4) / 4 > (now.stat[loc+4]-1) / 4)
		{
			nstat[2] = stat - 1;
			for(i=0; i<4; i++)
			{
				if(!sort[i])
				{
					sort[i] = 3;
					break;
				}
			}
		}
		else
		{
			nstat[2] = stat + 1;
			for(i=3; i>-1; i--)
			{
				if(!sort[i])
				{
					sort[i] = 3;
					break;
				}
			}
		}
	}
	if(loc % 4 < 3 && dir != 'L')
	{
		tmp[3] = now;
		tmp[3].stat[loc] = now.stat[loc+1];
		tmp[3].stat[loc+1] = now.stat[loc];
		if((loc+1) % 4 > (now.stat[loc+1]-1) % 4)
		{
			nstat[3] = stat - 1;
			for(i=0; i<4; i++)
			{
				if(!sort[i])
				{
					sort[i] = 4;
					break;
				}
			}
		}
		else
		{
			nstat[3] = stat + 1;
			for(i=3; i>-1; i--)
			{
				if(!sort[i])
				{
					sort[i] = 4;
					break;
				}
			}
		}
	}
	for(i=0; i<4; i++)
	{
		tmp2 = sort[i];
		if(tmp2--)
		{
			if(idfs(tmp[tmp2], depth+1, direct[tmp2], loc+way[tmp2], nstat[tmp2]))
			{
				ans[depth] = direct[tmp2];
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	char i, j, chkans, loc, stat;
	int buf, count;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, chkans=0, lim=0; i<16; i++)
		{
			scanf("%d", &buf);
			if(buf)
			{
				init[i] = buf;
				for(j=0; j<i; j++)
				{
					if(init[j] != 16 && init[j] > init[i])
					{
						chkans++;
					}
				}
				lim += dis(init[i], i);
			}
			else
			{
				init[i] = 16;
				loc = i;
				chkans += i / 4 + 1;
			}
		}
		if(chkans % 2)
		{
			printf("This puzzle is not solvable.\n");
		}
		else
		{
			strcpy(head.stat, init);
			stat = lim;
			while(1)
			{
				next = 45;
				if(idfs(head, 0, 0, loc, stat))
				{
					printf("%s\n", ans);
					break;
				}
				lim += next;
			}
		}
	}
	return 0;
}
