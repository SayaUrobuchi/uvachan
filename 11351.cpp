#include <stdio.h>

int next[100001];

int main()
{
	int cas, count, n, m, i, j, k;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			next[i] = i + 1;
		}
		next[i-1] = 0;
		for(i=0, k=n; n>1; n--)
		{
			for(j=(m-1)%n; j>0; j--)
			{
				k = i;
				i = next[i];
			}
			next[k] = next[i];
			i = next[k];
		}
		printf("Case %d: %d\n", ++cas, next[i]+1);
	}
	return 0;
}
