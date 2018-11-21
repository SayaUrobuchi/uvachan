#include <stdio.h>
#include <string.h>

int x[100], y[100], row[20], column[20];

int main()
{
	int count, i, j, dia1, dia2, over, p;
	scanf("%d", &count);
	while(count--)
	{
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));
		dia1 = dia2 = 1;
		for(i=0; i<5; i++)
		{
			row[i] = column[i] = 0;
			for(j=0; j<5; j++)
			{
				if(i == 2 && j == 2)
				{
					continue;
				}
				scanf("%d", &p);
				x[p] = i;
				y[p] = j;
			}
		}
		row[2] = column[2] = 1;
		for(i=0, over=0; i<75; i++)
		{
			scanf("%d", &p);
			if(over)
			{
				continue;
			}
			if(x[p] != -1)
			{
				row[x[p]]++;
				column[y[p]]++;
				if(x[p] == y[p])
				{
					dia1++;
				}
				if(x[p] + y[p] == 4)
				{
					dia2++;
				}
				if(row[x[p]] == 5 || column[y[p]] == 5 || dia1 == 5 || dia2 == 5)
				{
					over = 1;
					printf("BINGO after %d numbers announced\n", i+1);
				}
			}
		}
	}
	return 0;
}

