#include <stdio.h>
#include <string.h>

int n, id, flag, snum;
int stack[10][10];
int start[10];
int target[10];
int list[10];
char buf[11];

char* decode(int now)
{
	if(now == 1)
	{
		strcpy(buf, "ADD");
	}
	else if(now == 2)
	{
		strcpy(buf, "DIV");
	}
	else if(now == 3)
	{
		strcpy(buf, "DUP");
	}
	else if(now == 4)
	{
		strcpy(buf, "MUL");
	}
	else
	{
		strcpy(buf, "SUB");
	}
	return buf;
}

int overflow(int now)
{
	return now < -30000 || now > 30000;
}

int idfs(int depth)
{
	int i, temp[10], temp2[10];
	if(snum + depth > id + 1)
	{
		return 0;
	}
	if(depth == id)
	{
		for(i=0; i<n; i++)
		{
			if(stack[i][0] != target[i])
			{
				return 0;
			}
		}
		return 1;
	}
	if(snum > 1)
	{
		for(i=0; i<n; i++)
		{
			temp[i] = stack[i][snum-2];
			temp2[i] = stack[i][snum-1];
		}
	}
	if(snum > 1)
	{
		for(i=0, snum--; i<n; i++)
		{
			stack[i][snum-1] += stack[i][snum];
			if(overflow(stack[i][snum-1]))
			{
				break;
			}
		}
		if(i == n)
		{
			if(idfs(depth+1))
			{
				list[depth] = 1;
				return 1;
			}
		}
		for(i=0; i<n; i++)
		{
			stack[i][snum-1] = temp[i];
			stack[i][snum] = temp2[i];
		}
		snum++;
	}
	if(snum > 1)
	{
		for(i=0, snum--; i<n; i++)
		{
			if(!stack[i][snum])
			{
				break;
			}
			stack[i][snum-1] /= stack[i][snum];
		}
		if(i == n)
		{
			if(idfs(depth+1))
			{
				list[depth] = 2;
				return 1;
			}
		}
		for(i=0; i<n; i++)
		{
			stack[i][snum-1] = temp[i];
			stack[i][snum] = temp2[i];
		}
		snum++;
	}
	for(i=0; i<n; i++)
	{
		stack[i][snum] = stack[i][snum-1];
	}
	snum++;
	if(idfs(depth+1))
	{
		list[depth] = 3;
		return 1;
	}
	snum--;
	if(snum > 1)
	{
		for(i=0, snum--; i<n; i++)
		{
			stack[i][snum-1] *= stack[i][snum];
			if(overflow(stack[i][snum-1]))
			{
				break;
			}
		}
		if(i == n)
		{
			if(idfs(depth+1))
			{
				list[depth] = 4;
				return 1;
			}
		}
		for(i=0; i<n; i++)
		{
			stack[i][snum-1] = temp[i];
			stack[i][snum] = temp2[i];
		}
		snum++;
	}
	if(snum > 1)
	{
		for(i=0, snum--; i<n; i++)
		{
			stack[i][snum-1] -= stack[i][snum];
			if(overflow(stack[i][snum-1]))
			{
				break;
			}
		}
		if(i == n)
		{
			if(idfs(depth+1))
			{
				list[depth] = 5;
				return 1;
			}
		}
		for(i=0; i<n; i++)
		{
			stack[i][snum-1] = temp[i];
			stack[i][snum] = temp2[i];
		}
		snum++;
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &start[i]);
		}
		for(i=0, flag=1; i<n; i++)
		{
			scanf("%d", &target[i]);
			flag &= (target[i] == start[i]);
		}
		printf("Program %d\n", ++cas);
		if(flag)
		{
			printf("Empty sequence\n\n");
		}
		else
		{
			for(id=2; id<=10; id++)
			{
				for(i=0; i<n; i++)
				{
					stack[i][0] = start[i];
				}
				flag = snum = 1;
				if(idfs(0))
				{
					break;
				}
			}
			if(id > 10)
			{
				printf("Impossible");
			}
			else
			{
				printf("%s", decode(list[0]));
				for(i=1; i<id; i++)
				{
					printf(" %s", decode(list[i]));
				}
			}
			printf("\n\n");
		}
	}
	return 0;
}
