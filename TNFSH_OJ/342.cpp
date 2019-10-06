#include <stdio.h>

void draw2(int n)
{
	int i, j;
	for (j=3; j<n; j++)
	{
		putchar(n>26?'#':'A'+n-1);
		for (i=(n<<1)-3; i>0; i--)
		{
			putchar(' ');
		}
		putchar(n>26?'#':'A'+n-1);
		puts("");
	}
}

void draw(int space, int n)
{
	int i;
	for (i=0; i<space; i++)
	{
		putchar(' ');
	}
	for (i='A'+n-1; i>'A'+space; i--)
	{
		putchar(n>26?'#':i);
	}
	for (; i<='A'+n-1; i++)
	{
		putchar(n>26?'#':i);
	}
	puts("");
}

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		draw(0, n+1);
		draw2(n+1);
		draw(0, n+1);
		for (i=n+1, j=0; i>=1; i--, j++)
		{
			draw(j, n+1);
		}
	}
	return 0;
}
