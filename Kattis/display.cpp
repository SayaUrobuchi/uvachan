#include <iostream>

char tbl[10][8] = {
	"-|| ||-",
	"  |  | ",
	"- |-| -",
	"- |- |-",
	" ||- | ",
	"-| - |-",
	"-| -||-",
	"- |  | ",
	"-||-||-",
	"-||- |-"
};

void f0(int m, int s, int t)
{
	int a[] = {m/10, m%10, s/10, s%10};
	int i, j;
	for (i=0; i<4; i++)
	{
		if (i == 2)
		{
			printf("   ");
		}
		if (i)
		{
			printf("  ");
		}
		if (tbl[a[i]][t] != ' ' || (t-2 >= 0 && tbl[a[i]][t-2] != ' ') || (t+1 < 7 && tbl[a[i]][t+1] != ' '))
		{
			putchar('+');
		}
		else
		{
			putchar(' ');
		}
		for (j=0; j<3; j++)
		{
			putchar(tbl[a[i]][t]);
		}
		if (tbl[a[i]][t] != ' ' || (t-1 >= 0 && tbl[a[i]][t-1] != ' ') || (t+2 < 7 && tbl[a[i]][t+2] != ' '))
		{
			putchar('+');
		}
		else
		{
			putchar(' ');
		}
	}
	puts("");
}

void f1(int m, int s, int t, int u)
{
	int a[] = {m/10, m%10, s/10, s%10};
	int i, j, k;
	for (k=0; k<2; k++)
	{
		for (i=0; i<4; i++)
		{
			if (i == 2)
			{
				printf("  ");
				if ((t == 1 && k) || (t != 1 && !k))
				{
					putchar('o');
				}
				else
				{
					putchar(' ');
				}
			}
			if (i)
			{
				printf("  ");
			}
			printf("%c   %c", tbl[a[i]][t], tbl[a[i]][u]);
		}
		puts("");
	}
}

int main()
{
	int m, s;
	while (scanf("%d:%d", &m, &s) == 2)
	{
		f0(m, s, 0);
		f1(m, s, 1, 2);
		f0(m, s, 3);
		f1(m, s, 4, 5);
		f0(m, s, 6);
		puts("\n");
	}
	puts("end");
	return 0;
}
