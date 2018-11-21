#include <stdio.h>
#include <string.h>

int id, n1, c, sum;
int list1[20], list2[20];
int ary[20];
char ope[20];
char str[1000];

int dfs(int depth, int d1, int d2, int value)
{
	int i, p, q;
	if(value + value > sum)
	{
		return 0;
	}
	if(depth == id)
	{
		if(value+value == sum)
		{
			printf("%d", list1[0]);
			for(i=1, p=1, q=0; i<n1; i++)
			{
				if(ope[i] == '+')
				{
					printf(" %c %d", ope[i], list1[p++]);
				}
				else
				{
					printf(" %c %d", ope[i], list2[q++]);
				}
			}
			for(; i<id; i++)
			{
				if(ope[i] == '-')
				{
					printf(" %c %d", ope[i], list1[p++]);
				}
				else
				{
					printf(" %c %d", ope[i], list2[q++]);
				}
			}
			printf("\n");
			return 1;
		}
		return 0;
	}
	if(d1 < c)
	{
		list1[d1] = ary[depth];
		if(dfs(depth+1, d1+1, d2, value+ary[depth]))
		{
			return 1;
		}
	}
	if(id - depth + d1 > c)
	{
		list2[d2] = ary[depth];
		if(dfs(depth+1, d1, d2+1, value))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	char *ptr;
	while(gets(str))
	{
		if(!str[0]) continue;
		ptr = strtok(str, " ");
		sscanf(ptr, "%d", &ary[0]);
		ope[0] = '+';
		for(i=1, sum=ary[0], n1=0, c=1; ptr=strtok(NULL, " "); i++)
		{
			ope[i] = ptr[0];
			if(ope[i] == '=')
			{
				n1 = i;
			}
			else if((ope[i] == '+' && !n1) || (ope[i] == '-' && n1))
			{
				c++;
			}
			ptr = strtok(NULL, " ");
			sscanf(ptr, "%d", &ary[i]);
			sum += ary[i];
		}
		id = i;
		if(sum % 2 || !dfs(0, 0, 0, 0))
		{
			printf("no solution\n");
		}
	}
	return 0;
}
