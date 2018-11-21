#include <stdio.h>

#define N 10000004

int sn;
int stk[N+1], scc[N+1];

int main()
{
	int n, t, i, j, sum;
	while (scanf("%d", &n) == 1)
	{
		scanf("%d", &t);
		printf("0");
		sn = N;
		stk[sn] = t;
		scc[sn] = 1;
		for (i=1; i<n; i++)
		{
			scanf("%d", &t);
			for (j=sn, sum=0; j<=N&&stk[j]<t; sum+=scc[j], j++);
			printf(" %d", sum);
			scc[j-1] = sum+1;
			stk[j-1] = t;
			sn = j-1;
		}
		puts("");
	}
	return 0;
}
