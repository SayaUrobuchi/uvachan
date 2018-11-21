#include <stdio.h>

int ary[1500000];

int recurs(int n, int lim)
{
	int t;
	if(n == 1)
	{
		return 0;
	}
	t = recurs(n-1, lim);
	return (ary[lim-n+1]%n+t)%n;
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		printf("%d\n", recurs(n, n)+1);
	}
	return 0;
}
