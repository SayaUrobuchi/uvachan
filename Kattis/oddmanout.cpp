#include <stdio.h>
#include <algorithm>

int ary[1024];

int main()
{
	int count, cas, n, i;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0; i<n; i+=2)
		{
			if (i+1 >= n || ary[i] != ary[i+1])
			{
				break;
			}
		}
		printf("Case #%d: %d\n", ++cas, ary[i]);
	}
	return 0;
}
