#include <stdio.h>

int recurs(int n, int m, int k)
{
	if (!k)
	{
		return 0;
	}
	return (recurs(n-1, m, k-1)+m) % n;
}

int main()
{
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3)
	{
		printf("%d\n", recurs(n, m, k)+1);
	}
	return 0;
}
