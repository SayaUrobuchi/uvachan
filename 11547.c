#include <stdio.h>

int ab(int p)
{
	return p>0 ? p : -p;
}

int main()
{
	int count, n;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", ab((n * 567 / 9 + 7492) * 235 / 47 - 498) % 100 / 10);
	}
	return 0;
}
