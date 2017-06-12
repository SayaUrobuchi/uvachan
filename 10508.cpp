#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;
int next[5000];
int index[5000];
int list[5000];
char str[5000][2000];
char first[2000], final[2000];
char s[2000];

int comp(const void *p, const void *q)
{
	return strcmp(str[*(int*)p], str[*(int*)q]);
}

int bisearch(int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = strcmp(str[index[center]], s);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1);
	}
	return bisearch(center+1, right);
}

int dfs(int depth)
{
	int i, j;
	if(!next[0])
	{
		for(i=0; i<depth; i++)
		{
			printf("%s\n", str[list[i]]);
		}
		return 1;
	}
	for(i=0; j=next[i]; i=j)
	{
		s[j-1] = final[j-1];
		next[i] = next[j];
		if((list[depth]=bisearch(0, m-1))!=-1)
		{
			if(dfs(depth+1))
			{
				return 1;
			}
		}
		s[j-1] = first[j-1];
		next[i] = j;
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d", &m, &n) == 2)
	{
		scanf("%s%s", first, final);
		for(i=0, m-=2; i<m; i++)
		{
			scanf("%s", str[i]);
			index[i] = i;
		}
		strcpy(str[m], final);
		index[m] = m;
		m++;
		for(i=0; i<n; i++)
		{
			next[i] = i + 1;
		}
		next[i] = 0;
		qsort(index, m, sizeof(int), comp);
		printf("%s\n", first);
		strcpy(s, first);
		dfs(0);
	}
	return 0;
}
