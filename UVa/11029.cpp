#include <stdio.h>
#include <math.h>

int recursion(int n, int k)
{
	int tmp;
	if(k == 1)
	{
		return n;
	}
	if(k % 2)
	{
		return (n * recursion(n, k-1)) % 1000;
	}
	tmp = recursion(n, k/2);
	return (tmp * tmp) % 1000;
}

int main()
{
	int count, n, k;
	double head;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		head = log10(n);
		head *= k;
		head -= (int)head;
		head += 2;
		printf("%d...%03d\n", (int)pow(10, head), recursion(n % 1000, k));
	}
	return 0;
}