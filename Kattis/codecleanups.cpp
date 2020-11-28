#include <iostream>

int ary[1048576];

int main()
{
	int n, i, j, c, d, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=1, j=0, c=0, d=0, ans=0; i<=365; i++)
		{
			if (i == ary[j])
			{
				++j;
				++c;
			}
			d += c;
			if (d >= 20)
			{
				++ans;
				c = 0;
				d = 0;
			}
		}
		if (c)
		{
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
