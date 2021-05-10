#include <iostream>
#include <algorithm>

int ary[1024];

int main()
{
	int count, n, nnn, i, j, sum;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		nnn = n+n+n;
		for (i=0; i<nnn; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+nnn, std::greater<int>());
		for (i=1, j=0, sum=0; j<n; sum+=ary[i], i+=2, j++);
		printf("%d\n", sum);
	}
	return 0;
}