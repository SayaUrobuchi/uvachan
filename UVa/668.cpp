#include <stdio.h>

int ans[40];

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=2, j=2, k=0; j<=n; i++, j+=i, k++)
		{
			ans[k] = i;
		}
		j -= i;
		n -= j;
		i = k - 1;
		while(n--)
		{
			ans[i--]++;
			if(i < 0)
			{
				i = k - 1;
			}
		}
		printf("%d", ans[0]);
		for(i=1; i<k; i++)
		{
			printf(" %d", ans[i]);
		}
		printf("\n");
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
