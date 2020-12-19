#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0; i<n&&m>=ary[i]+1; m-=ary[i++]+1);
		printf("%d\n", i);
	}
	return 0;
}
