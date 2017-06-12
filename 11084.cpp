#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c, n, d;
int next[11];
char str[11];
char chk[11];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

void dfs(long long value, int depth)
{
	int i, j, last;
	if(depth == n)
	{
		if(!(value % d))
		{
			c++;
		}
		return;
	}
	value *= 10;
	for(i=0, last=-1; j=next[i]; i=j)
	{
		if(last == -1 || str[last-1] != str[j-1])
		{
			next[i] = next[j];
			dfs(value+str[j-1], depth+1);
		}
		next[i] = last = j;
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &d);
		for(i=0; str[i]; i++)
		{
			str[i] -= 48;
			next[i] = i+1;
		}
		next[i] = 0;
		n = i;
		qsort(str, n, sizeof(char), comp);
		memset(chk, 1, sizeof(chk));
		c = 0;
		dfs(0, 0);
		printf("%d\n", c);
	}
	return 0;
}
