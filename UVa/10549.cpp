#include <stdio.h>
#include <stdlib.h>

int n, tmp, ary[100], ary2[100], doll[200][5];

int comp(const void *p, const void *q)
{
	if(((int*)p)[0] == ((int*)q)[0])
	{
		return ((int*)q)[1] - ((int*)p)[1];
	}
	return ((int*)q)[1] - ((int*)p)[1];
}

char dfs(int depth, int left, int right)
{
	if(depth == tmp)
	{
		return 1;
	}
	if(left < n)
	{
		if(!left || doll[ary[left-1]][3] >= doll[depth][0] && doll[ary[left-1]][4] >= doll[depth][1])
		{
			ary[left] = depth;
			if(dfs(depth+1, left+1, right))
			{
				return 1;
			}
		}
	}
	if(right < n)
	{
        if(!right || doll[ary2[right-1]][3] >= doll[depth][0] && doll[ary2[right-1]][4] >= doll[depth][1])
		{
			ary2[right] = depth;
			if(dfs(depth+1, left, right+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	char bline;
	bline = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(bline)
		{
			printf("\n");
		}
		bline = 1;
		for(i=0, tmp=n*2; i<tmp; i++)
		{
			scanf("%d%d%d", &doll[i][0], &doll[i][1], &doll[i][2]);
			doll[i][3] = doll[i][0] - doll[i][2] - doll[i][2];
			doll[i][4] = doll[i][1] - doll[i][2] - doll[i][2];
		}
		qsort(doll, tmp, 20, comp);
		/*printf("\n\n");
		for(i=0; i<tmp; i++)
		{
			printf("%d %d %d\n", doll[i][0], doll[i][1], doll[i][2]);
		}
		printf("%d\n", dfs(0, 0, 0));*/
		dfs(0, 0, 0);
		for(i=0; i<n; i++)
		{
			tmp = ary[i];
			printf("%d %d %d\n", doll[tmp][0], doll[tmp][1], doll[tmp][2]);
		}
		printf("-\n");
		for(i=0; i<n; i++)
		{
			tmp = ary2[i];
			printf("%d %d %d\n", doll[tmp][0], doll[tmp][1], doll[tmp][2]);
		}
	}
	return 0;
}
