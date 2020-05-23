#include <stdio.h>
#include <algorithm>

int ary[8];

int main()
{
	int i, j, k;
	while (scanf("%d", &ary[0]) == 1)
	{
		for (i=1; i<5; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<4; i++)
		{
			for (j=1; j<5-i; j++)
			{
				if (ary[j-1] > ary[j])
				{
					std::swap(ary[j-1], ary[j]);
					printf("%d", ary[0]);
					for (k=1; k<5; k++)
					{
						printf(" %d", ary[k]);
					}
					puts("");
				}
			}
		}
	}
	return 0;
}
