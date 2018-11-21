/*
	ID: sa072682
	LANG: C
	TASK: fracdec
*/
#include <stdio.h>
#include <string.h>

int tbl[101001];
char str[101001];

int main()
{
	int n, m, i, j;
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	scanf("%d%d", &n, &m);
	sprintf(str, "%d.", n/m);
	n %= m;
	if(n)
	{
		for(i=strlen(str); ; i++)
		{
			if(tbl[n] || !n)
			{
				str[i] = 0;
				break;
			}
			tbl[n] = i + 1;
			n *= 10;
			str[i] = n / m + 48;
			n %= m;
		}
		for(i=0, j=0; str[i]; i++, j++)
		{
			if(j && !(j % 76))
			{
				printf("\n");
			}
			if(i == tbl[n] - 1)
			{
				printf("(");
				i--;
				tbl[n] = -1;
			}
			else
			{
				printf("%c", str[i]);
			}
		}
		if(tbl[n] == -1)
		{
			if(j && !(j % 76))
			{
				printf("\n");
			}
			printf(")\n");
		}
		else
		{
			printf("\n");
		}
	}
	else
	{
		printf("%s0\n", str);
	}
	scanf(" ");
	return 0;
}
