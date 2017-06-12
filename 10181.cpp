#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char stat[17];
	data *left, *right;
};

char init[17], ans[60], lim, next;
data *head, *ptr;

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

char find(data now)
{
	char comp;
	ptr = head;
	while(1)
	{
		comp = strcmp(ptr -> stat, now.stat);
		if(!comp)
		{
			return 0;
		}
		if(comp > 0)
		{
			if(ptr -> left)
			{
				ptr = ptr -> left;
			}
			else
			{
				ptr -> left = (data*)malloc(sizeof(data));
				ptr = ptr -> left;
				*ptr = now;
				ptr -> left = NULL;
				ptr -> right = NULL;
				return 1;
			}
		}
		else
		{
			if(ptr -> right)
			{
				ptr = ptr -> right;
			}
			else
			{
				ptr -> right = (data*)malloc(sizeof(data));
				ptr = ptr -> right;
				*ptr = now;
				ptr -> left = NULL;
				ptr -> right = NULL;
				return 1;
			}
		}
	}
}

void del(data now)
{
	char comp, type;
	data *pre;
	ptr = head;
	while(1)
	{
		comp = strcmp(ptr -> stat, now.stat);
		if(!comp)
		{
			free(ptr);
			if(type)
			{
				if(pre == head)
				{
					head -> right = NULL;
				}
				else
				{
					pre -> right = NULL;
				}
			}
			else
			{
				if(pre == head)
				{
					head -> left = NULL;
				}
				else
				{
					pre -> left = NULL;
				}
			}
			return;
		}
		if(comp > 0)
		{
			pre = ptr;
			ptr = ptr -> left;
			type = 0;
		}
		else
		{
			pre = ptr;
			ptr = ptr -> right;
			type = 1;
		}
	}
}

int idfs(data now, int depth, char dir, int loc, int stat)
{
	data tmp[4];
	int nstat[4], sort[4], i;
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
		if(sort[i])
		{
			if(sort[i] == 1)
			{
				if(find(tmp[0]))
				{
					if(idfs(tmp[0], depth+1, 'U', loc-4, nstat[0]))
					{
						del(tmp[0]);
						ans[depth] = 'U';
						/*for(i=0; i<16; i++)
						{
							printf("%3d", tmp[0].stat[i]);
							if(i % 4 == 3)
							{
								printf("\n");
							}
						}
						printf("%d\n", nstat[0]);*/
						return 1;
					}
					del(tmp[0]);
				}
			}
			else if(sort[i] == 2)
			{
				if(find(tmp[1]))
				{
					if(idfs(tmp[1], depth+1, 'L', loc-1, nstat[1]))
					{
						del(tmp[1]);
						ans[depth] = 'L';
						/*for(i=0; i<16; i++)
						{
							printf("%3d", tmp[1].stat[i]);
							if(i % 4 == 3)
							{
								printf("\n");
							}
						}
						printf("%d\n", nstat[1]);*/
						return 1;
					}
					del(tmp[1]);
				}
			}
			else if(sort[i] == 3)
			{
				if(find(tmp[2]))
				{
					if(idfs(tmp[2], depth+1, 'D', loc+4, nstat[2]))
					{
						del(tmp[2]);
						ans[depth] = 'D';
						/*for(i=0; i<16; i++)
						{
							printf("%3d", tmp[2].stat[i]);
							if(i % 4 == 3)
							{
								printf("\n");
							}
						}
						printf("%d\n", nstat[2]);*/
						return 1;
					}
					del(tmp[2]);
				}
			}
			else
			{
				if(find(tmp[3]))
				{
					if(idfs(tmp[3], depth+1, 'R', loc+1, nstat[3]))
					{
						del(tmp[3]);
						ans[depth] = 'R';
						/*for(i=0; i<16; i++)
						{
							printf("%3d", tmp[3].stat[i]);
							if(i % 4 == 3)
							{
								printf("\n");
							}
						}
						printf("%d\n", nstat[3]);*/
						return 1;
					}
					del(tmp[3]);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, buf, chkans, loc, stat;
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
				/*printf("%d %d\n", init[i], dis(init[i], i));*/
			}
			else
			{
				init[i] = 16;
				loc = i;
				chkans += i / 4 + 1;
			}
		}
		if(lim)
		{
			if(chkans % 2)
			{
				printf("This puzzle is not solvable.\n");
			}
			else
			{
				head = (data*)malloc(sizeof(data));
				strcpy(head -> stat, init);
				head -> left = NULL;
				head -> right = NULL;
				stat = lim;
				while(1)
				{
					next = 45;
					if(idfs(*head, 0, 0, loc, stat))
					{
						printf("%s\n", ans);
						free(head);
						break;
					}
					lim += next;
					if(lim > 45)
					{
						while(printf("ljdsaof;jdsafndlwahjkgorwlqngshdaoghsanogfhdsaogh\n"));
					}
				}
			}
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
