#include <stdio.h>

int main()
{
	int count, n;
	long long t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		t = 1;
		while (n>1)
		{
			t = ((t<<1) | 1);
			--n;
		}
		printf("%lld\n", t);
	}
	return 0;
}
