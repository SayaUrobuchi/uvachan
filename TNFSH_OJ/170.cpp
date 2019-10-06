#include <stdio.h>

char type[8];

void draw(int space, int n, char c)
{
	int i;
	for (i=0; i<space; i++)
	{
		putchar(' ');
	}
	for (i=0; i<n; i++)
	{
		putchar(c);
	}
	puts("");
}

void tree(int n, int ss)
{
	int i, j, k;
	for (i=1, j=n-1+ss, k=1; i<=n; i++, j--, k+=2)
	{
		draw(j, k, '*');
	}
}

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%d", type, &n);
		switch (*type)
		{
		case 'B':
			tree(n, 0);
		case 'A':
			tree(n, 0);
			break;
		case 'C':
			for (i=1, j=n-i; i<=n; i++, j--)
			{
				tree(i, j);
			}
			break;
		case 'D':
			tree(n*10, 0);
			break;
		case 'E':
			tree(n, 2);
			draw(0, (n<<1)+3, '#');
			break;
		case 'F':
			tree(n<<1, 0);
			break;
		case 'G':
			tree(n*3, 0);
			break;
		case 'H':
			tree(n*7, 0);
			break;
		case 'I':
			tree((n<<2)-1, 0);
			break;
		}
		puts("");
	}
	return 0;
}
