#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, i, j;
	bool first;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, first=true; i<n; )
		{
			if (!first)
			{
				putchar(' ');
			}
			first = false;
			for (j=i+1; j<n&&ary[j]==ary[j-1]+1; j++);
			if (j-i <= 2)
			{
				printf("%d", ary[i]);
				++i;
			}
			else
			{
				printf("%d-%d", ary[i], ary[j-1]);
				i = j;
			}
		}
		puts("");
	}
	return 0;
}
