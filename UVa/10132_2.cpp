#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, l;
int index[300];
int length[300];
int used[300];
int tbl[2100];
char ary[300][2100];
char temp[2100], buf[2100];

int comp(const void *p, const void *q)
{
	return length[*(int*)p] - length[*(int*)q];
}

int dfs(int depth)
{
	int i, j, now, target;
	if(depth == m)
	{
		puts(temp);
		return 1;
	}
	for(i=depth; i<n; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			now = index[i];
			for(j=tbl[l-length[now]]; j<n; j++)
			{
				target = index[j];
				if(length[target] != l-length[now])
				{
					break;
				}
				used[j] = 1;
				if(depth)
				{
					if(!strncmp(temp, ary[now], length[now]) && !strcmp(temp+length[now], ary[target]) && dfs(depth+1))
					{
						return 1;
					}
				}
				else
				{
					sprintf(temp, "%s%s\0", ary[now], ary[target]);
					if(dfs(depth+1))
					{
						return 1;
					}
				}
				used[j] = 0;
			}
			for(j=tbl[l-length[now]]; j<n; j++)
			{
				target = index[j];
				if(length[target] != l-length[now])
				{
					break;
				}
				used[j] = 1;
				if(depth)
				{
					if(!strncmp(temp, ary[target], length[target]) && !strcmp(temp+length[target], ary[now]) && dfs(depth+1))
					{
						return 1;
					}
				}
				else
				{
					sprintf(temp, "%s%s\0", ary[target], ary[now]);
					if(dfs(depth+1))
					{
						return 1;
					}
				}
				used[j] = 0;
			}
			used[i] = 0;
			return 0;
		}
	}
}

int main()
{
	int count, i, min, max;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		max = -1;
		min = 1000000;
		n = 0;
		while(gets(ary[n]))
		{
			if(!ary[n][0])
			{
				break;
			}
			length[n] = strlen(ary[n]);
			if(length[n] > max)
			{
				max = length[n];
			}
			if(length[n] < min)
			{
				min = length[n];
			}
			index[n] = n;
			n++;
		}
		m = (n >> 1);
		l = min + max;
		qsort(index, n, sizeof(int), comp);
		tbl[length[index[0]]] = 0;
		for(i=1; i<n; i++)
		{
			if(length[index[i]] != length[index[i-1]])
			{
				tbl[length[index[i]]] = i;
			}
		}
		memset(used, 0, sizeof(used));
		dfs(0);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
