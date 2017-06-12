#include <stdio.h>

int a[15], b[15];

int main()
{
	int n, i, count;
	a[1] = 0;
	b[1] = 1;
	for(i=2; i<=12; i++)
	{
		a[i] = a[i-1]*i+((i&1)?-1:1);
		b[i] = b[i-1]*i;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d/%d\n", a[n], b[n]);
	}
	return 0;
}
