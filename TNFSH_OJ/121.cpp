#include <stdio.h>

int main()
{
	int n, i, j, k;
	char c;
	while (scanf("%d", &n) == 1)
	{
		for (i=(n<<1)-1, j=0, c='A'+n-1; i>0; i-=2, j++, c--)
		{
			for (k=0; k<j; k++)
			{
				putchar(' ');
			}
			for (k=0; k<i; k++)
			{
				putchar(c);
			}
			puts("");
		}
	}
	return 0;
}
