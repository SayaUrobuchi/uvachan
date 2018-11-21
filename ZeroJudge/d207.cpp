#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char init[17];
int lim, next;

int dis(int n, int loc)
{
	int i, j;
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

int idfs(int depth, int dir, int loc, int stat)
{
	int ns;
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
		return 1;
	}
	if(loc >= 4 && dir != 'D')
	{
		init[loc] = init[loc-4];
		init[loc-4] = 16;
		if((init[loc]>>2) >= (loc>>2))
		{
			ns = stat - 1;
		}
		else
		{
			ns = stat + 1;
		}
		if(idfs(depth+1, 'U', loc-4, ns))
		{
			return 1;
		}
		init[loc-4] = init[loc];
		init[loc] = 16;
	}
	if(loc <= 11 && dir != 'U')
	{
		init[loc] = init[loc+4];
		init[loc+4] = 16;
		if((init[loc]>>2) <= (loc>>2))
		{
			ns = stat - 1;
		}
		else
		{
			ns = stat + 1;
		}
		if(idfs(depth+1, 'D', loc+4, ns))
		{
			return 1;
		}
		init[loc+4] = init[loc];
		init[loc] = 16;
	}
	if(loc % 4 && dir != 'R')
	{
		init[loc] = init[loc-1];
		init[loc-1] = 16;
		if((init[loc]%4) >= (loc%4))
		{
			ns = stat - 1;
		}
		else
		{
			ns = stat + 1;
		}
		if(idfs(depth+1, 'L', loc-1, ns))
		{
			return 1;
		}
		init[loc-1] = init[loc];
		init[loc] = 16;
	}
	if(loc % 4 < 3 && dir != 'L')
	{
		init[loc] = init[loc+1];
		init[loc+1] = 16;
		if((init[loc]%4) <= (loc%4))
		{
			ns = stat - 1;
		}
		else
		{
			ns = stat + 1;
		}
		if(idfs(depth+1, 'R', loc+1, ns))
		{
			return 1;
		}
		init[loc+1] = init[loc];
		init[loc] = 16;
	}
	return 0;
}

int main()
{
	int i, j, chkans, loc, stat;
	int buf, count;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, chkans=0, lim=0; i<16; i++)
		{
			scanf("%d", &buf);
			if(buf)
			{
				init[i] = buf-1;
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
			stat = lim;
			while(1)
			{
				next = 1000;
				if(idfs(0, 0, loc, stat))
				{
					//printf("%s\n", ans);
					printf("%d\n", lim);
					break;
				}
				lim += next;
			}
		}
	}
	return 0;
}
