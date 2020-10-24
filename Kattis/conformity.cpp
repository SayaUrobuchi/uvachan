#include <iostream>
#include <algorithm>

long long tmp[5], ary[1048576];

int main()
{
	int n, i, j, k, ans;
	long long t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<5; j++)
			{
				scanf("%d", &tmp[j]);
			}
			std::sort(tmp, tmp+5);
			for (j=0, t=0; j<5; j++)
			{
				t = t*1000 + tmp[j];
			}
			ary[i] = t;
		}
		std::sort(ary, ary+n);
		for (i=0, k=0, t=0; i<n; i=j, k++)
		{
			for (j=i+1; j<n&&ary[i]==ary[j]; j++);
			ary[k] = j-i;
			if (ary[k] > t)
			{
				t = ary[k];
			}
		}
		for (i=0, ans=0; i<k; i++)
		{
			if (ary[i] == t)
			{
				ans += t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
