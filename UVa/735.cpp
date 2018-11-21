#include <stdio.h>

int tbl[61];
int permutation[181];
int combination[181];
int list[3];

void dfs(int depth, int last)
{
	int i, p;
	if(depth == 3)
	{
		if(list[0] == list[1] && list[1] == list[2])
		{
			p = 1;
		}
		else if(list[0] == list[1] || list[1] == list[2])
		{
			p = 3;
		}
		else
		{
			p = 6;
		}
		combination[list[0]+list[1]+list[2]]++;
		permutation[list[0]+list[1]+list[2]] += p;
		return;
	}
	for(i=last; i<61; i++)
	{
		if(tbl[i])
		{
			list[depth] = i;
			dfs(depth+1, i);
		}
	}
}

int main()
{
	int n, i, j, k;
	tbl[0] = tbl[50] = 1;
	for(i=1; i<21; i++)
	{
		tbl[i] = tbl[i+i] = tbl[i+i+i] = 1;
	}
	dfs(0, 0);
	while(scanf("%d", &n) == 1)
	{
		if(n <= 0)
		{
			break;
		}
		if(n <= 180 && permutation[n])
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combination[n]);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutation[n]);
		}
		else
		{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
	return 0;
}
