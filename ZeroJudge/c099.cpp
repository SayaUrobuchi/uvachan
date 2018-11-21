#include <stdio.h>
#include <string.h>

char name[300][32], buf[32], buf2[32];
int tmp, tmp2, n, parent[300], relation[300];

int insertion(char* str)
{
	int i, j, comp;
	for(i=0; i<n; i++)
	{
		comp = strcmp(str, name[i]);
		if(!comp)
		{
			return i;
		}
	}
	strcpy(name[n++], str);
	return i;
}

void recursion(int now, int depth)
{
	if(now == -1)
	{
		return;
	}
	relation[now] = depth;
	recursion(parent[now], depth+1);
}

char recursion2(int now, int depth)
{
	int i, j;
	if(now == -1)
	{
		return 0;
	}
	if(now == tmp)
	{
		if(depth > 2)
		{
			for(i=depth; i>2; i--)
			{
				printf("great ");
			}
		}
		if(depth > 1)
		{
			printf("grand ");
		}
		printf("parent\n");
		return 1;
	}
	if(relation[now])
	{
		i = relation[now];
		j = depth;
		if(i == 1 && j == 1)
		{
			printf("sibling\n");
			return 1;
		}
		if(i > j)
		{
			printf("%d cousin", j-1);
			if(i - j)
			{
				printf(" removed %d", i-j);
			}
			printf("\n");
		}
		else
		{
			printf("%d cousin", i-1);
			if(j - i)
			{
				printf(" removed %d", j-i);
			}
			printf("\n");
		}
		return 1;
	}
	return recursion2(parent[now], depth+1);
}

int main()
{
	int i;
	n = 0;
	for(i=0; i<300; i++)
	{
		parent[i] = -1;
	}
	while(scanf("%s%s", buf, buf2) == 2)
	{
		if(!strcmp(buf, "no.child"))
		{
			break;
		}
		parent[insertion(buf)] = insertion(buf2);
	}
	while(scanf("%s%s", buf, buf2) == 2)
	{
		memset(relation, 0, sizeof(relation));
		tmp = insertion(buf);
		tmp2 = insertion(buf2);
		recursion(parent[tmp], 1);
		if(relation[tmp2])
		{
			if(relation[tmp2] > 2)
			{
				for(i=relation[tmp2]; i>2; i--)
				{
					printf("great ");
				}
			}
			if(relation[tmp2] > 1)
			{
				printf("grand ");
			}
			printf("child\n");
			continue;
		}
		if(!recursion2(parent[tmp2], 1))
		{
			printf("no relation\n");
		}
	}
	return 0;
}
