#include <stdio.h>

const char *tbl[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int i, j, k, d, y;
	while (scanf("%d%d", &d, &y) == 2)
	{
		for (i=1, j=1, k=0; i!=d||j!=y; i++, k++)
		{
			if (i > day[j])
			{
				i = 1;
				j++;
			}
			if (i==d && j==y)
			{
				break;
			}
		}
		puts(tbl[k%7]);
	}
	return 0;
}