#include <stdio.h>
#include <string.h>

#define N 24

int ary[6];
int list[N][6] = {	{0, 2, 1, 4, 5, 3}, 
					{0, 5, 2, 1, 4, 3}, 
					{0, 4, 5, 2, 1, 3}, 
					{0, 1, 4, 5, 2, 3}, 
					{1, 2, 3, 4, 0, 5}, 
					{1, 0, 2, 3, 4, 5}, 
					{1, 4, 0, 2, 3, 5}, 
					{1, 3, 4, 0, 2, 5}, 
					{2, 5, 3, 1, 0, 4}, 
					{2, 0, 5, 3, 1, 4}, 
					{2, 1, 0, 5, 3, 4}, 
					{2, 3, 1, 0, 5, 4}, 
					{3, 4, 1, 2, 5, 0}, 
					{3, 5, 4, 1, 2, 0}, 
					{3, 2, 5, 4, 1, 0}, 
					{3, 1, 2, 5, 4, 0}, 
					{4, 1, 3, 5, 0, 2}, 
					{4, 0, 1, 3, 5, 2}, 
					{4, 5, 0, 1, 3, 2}, 
					{4, 3, 5, 0, 1, 2}, 
					{5, 4, 3, 2, 0, 1}, 
					{5, 0, 4, 3, 2, 1}, 
					{5, 2, 0, 4, 3, 1}, 
					{5, 3, 2, 0, 4, 1}};
char hash[50000];

int calculate(int num)
{
	int i, res;
	for(i=0, res=0; i<6; i++)
	{
		res *= 6;
		res += ary[list[num][i]];
	}
	return res;
}

int main()
{
	int n, i, c, temp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(hash, 0, sizeof(hash));
		c = 0;
		while(n--)
		{
			for(i=0; i<6; i++)
			{
				scanf("%d", &ary[i]);
				ary[i]--;
			}
			for(i=0; i<N; i++)
			{
				if(hash[temp=calculate(i)])
				{
					break;
				}
			}
			if(i == N)
			{
				hash[temp] = 1;
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
