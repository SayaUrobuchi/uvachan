#include <iostream>

int ary[16];

int main()
{
	int cas, count, i, j, t, ans;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<13; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=1, ans=0; i<12; i++)
		{
			for (j=i, t=ary[i]; j<12&&t>ary[i-1]; t=std::min(t, ary[++j]))
			{
				if (t > ary[j+1])
				{
					++ans;
				}
			}
		}
		printf("%d %d\n", ++cas, ans);
	}
	return 0;
}
