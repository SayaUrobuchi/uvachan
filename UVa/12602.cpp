#include <stdio.h>

char s[1024];

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%3s-%d", s, &n);
		for (i=2, j=1; i>=0; i--, j*=26)
		{
			n -= (s[i]-'A') * j;
		}
		printf(n>=-100 && n<=100 ? "nice\n" : "not nice\n");
	}
	return 0;
}
