#include <stdio.h>
#include <string.h>

int node[20][2000], num[20], m;

void recursion(int next, int depth)
{
	int i, now;
	node[depth][num[depth]++] = now = m++;
	for(i=1; i<next; i++)
	{
		printf("%d %d\n", now, m);
		recursion(i, depth+1);
	}
}

int main()
{
	int n, i, j, f;
	while(scanf("%d", &n) == 1)
	{
		printf("%d %d\n", 1<<(n-1), (1<<(n-1))-1);
		m = 1;
		memset(num, 0, sizeof(num));
		recursion(n, 0);
		for(i=n-1, f=0; i>=0; i--)
		{
			for(j=0; j<num[i]; j++)
			{
				if(f)
				{
					printf(" ");
				}
				f = 1;
				printf("%d", node[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
