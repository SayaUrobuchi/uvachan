#include <stdio.h>
#include <string.h>

int num, snum, rnum;
char list[100];
char start[100];
char target[100];
char stack[100];
char result[100];

void dfs(int depth, int limit)
{
	int i, temp;
	if(depth == limit)
	{
		printf("%c", list[0]);
		for(i=1; i<limit; i++)
		{
			printf(" %c", list[i]);
		}
		printf("\n");
		return;
	}
	if(start[num])
	{
		stack[snum++] = start[num++];
		list[depth] = 'i';
		dfs(depth+1, limit);
		snum--;
		num--;
	}
	if(snum && stack[snum-1] == target[rnum])
	{
		result[rnum++] = temp = stack[--snum];
		list[depth] = 'o';
		dfs(depth+1, limit);
		rnum--;
		stack[snum++] = temp;
	}
}

int main()
{
	int len;
	while(gets(start))
	{
		gets(target);
		num = 0;
		snum = 0;
		rnum = 0;
		len = strlen(target);
		puts("[");
		dfs(0, len+len);
		puts("]");
	}
	return 0;
}
