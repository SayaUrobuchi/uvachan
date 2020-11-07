#include <iostream>

int ary[32];

int main()
{
	int count, cas, i, j, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &cas);
		for (i=0, ans=0; i<20; i++)
		{
			scanf("%d", &ary[i]);
			for (j=i; j>0&&ary[j]<ary[j-1]; j--, ans++)
			{
				std::swap(ary[j], ary[j-1]);
			}
		}
		printf("%d %d\n", cas, ans);
	}
	return 0;
}
