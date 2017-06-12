#include <stdio.h>

int recursion(int n, int m)
{
	if(n == 1)
	{
		return 0;
	}
	return (recursion(n-1, m) + m) % n;
}

int main()
{
	int cas, count, n, m, i, j, k;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", ++cas, recursion(n, m) + 1);
	}
	return 0;
}
