#include <stdio.h>

int m, tower[3][250], pointer[3];

void output()
{
	int i, j;
	for(i=0; i<3; i++)
	{
		if(pointer[i])
		{
			printf("%c=>  ", i+65);
			for(j=0; j<pointer[i]; j++)
			{
				printf(" %d", tower[i][j]);
			}
			printf("\n");
		}
		else
		{
			printf("%c=>\n", i+65);
		}
	}
	printf("\n");
}

void recursion(int now, int start, int target)
{
	if(!now)
	{
		return;
	}
	recursion(now-1, start, 3-start-target);
	if(!m)
	{
		return;
	}
	tower[target][pointer[target]++] = tower[start][--pointer[start]];
	output();
	m--;
	if(!m)
	{
		return;
	}
	recursion(now-1, 3-start-target, target);
}

int main()
{
	int cas, n, i, j;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		printf("Problem #%d\n\nA=>  ", ++cas);
		for(i=n, j=0; i>0; i--, j++)
		{
			printf(" %d", i);
			tower[0][j] = i;
		}
		printf("\nB=>\nC=>\n\n");
		pointer[0] = n;
		pointer[1] = 0;
		pointer[2] = 0;
		recursion(n, 0, 2);
	}
	return 0;
}