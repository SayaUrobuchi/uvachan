#include <stdio.h>

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i='A'+n-1, j=n-1; i>='A'; i--, j--)
		{
			for (k=0; k<j; k++)
			{
				putchar(' ');
			}
			for (k='A'+n-1; k>i; k--)
			{
				putchar(k);
			}
			for (; k<='A'+n-1; k++)
			{
				putchar(k);
			}
			puts("");
		}
		for (i='A'+1, j=1; j<n; i++, j++)
		{
			for (k=0; k<j; k++)
			{
				putchar(' ');
			}
			for (k='A'+n-1; k>i; k--)
			{
				putchar(k);
			}
			for (; k<='A'+n-1; k++)
			{
				putchar(k);
			}
			puts("");
		}
	}
	return 0;
}
