#include <stdio.h>
#include <algorithm>

int ary[4];

int main()
{
	int i, j;
	while (scanf("%d%d%d%d", &ary[0], &ary[1], &ary[2], &ary[3]) == 4)
	{
		for (i=1; i<4; i++)
		{
			for (j=i; j>0&&ary[j]<ary[j-1]; std::swap(ary[j], ary[j-1]), j--);
		}
		printf("%d\n", ary[0]*ary[2]);
	}
	return 0;
}
