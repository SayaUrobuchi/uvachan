#include <iostream>
#include <algorithm>

int ary[4];

int main()
{
	int a, b;
	while (scanf("%d%d%d", &ary[0], &ary[1], &ary[2]) == 3)
	{
		std::sort(ary, ary+3);
		a = ary[1] - ary[0];
		b = ary[2] - ary[1];
		if (a == b)
		{
			printf("%d\n", ary[2]+a);
		}
		else if (a > b)
		{
			printf("%d\n", ary[0]+b);
		}
		else
		{
			printf("%d\n", ary[1]+a);
		}
	}
	return 0;
}
