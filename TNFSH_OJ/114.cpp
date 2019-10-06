#include <stdio.h>

int ary[8][8];

int main()
{
	int i, j, gg;
	gg = 0;
	for (i=0; i<5&&!gg; i++)
	{
		for (j=0; j<6&&!gg; j++)
		{
			scanf("%d", &ary[i][j]);
			if (i >= 2 && ary[i][j] == ary[i-1][j] && ary[i][j] == ary[i-2][j])
			{
				gg = 1;
			}
			else if (j >= 2 && ary[i][j] == ary[i][j-1] && ary[i][j] == ary[i][j-2])
			{
				gg = 1;
			}
		}
	}
	puts(gg?"Yes":"No");
	return 0;
}
