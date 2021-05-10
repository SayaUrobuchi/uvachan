#include <iostream>
#include <algorithm>

int ary[1048576], bry[1048576];

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, j=n-1, k=0; i<=j; i++, j--)
		{
			bry[k++] = ary[i];
			if (i < j)
			{
				bry[k++] = ary[j];
			}
		}
		std::reverse(bry, bry+n);
		printf("%d", bry[0]);
		for (i=1; i<n; i++)
		{
			printf(" %d", bry[i]);
		}
		puts("");
	}
	return 0;
}