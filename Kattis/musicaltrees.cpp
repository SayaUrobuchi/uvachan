#include <iostream>
#include <algorithm>

int ary[1024], bry[1024];

int main()
{
	int n, m, i, j, t, last, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &bry[i]);
		}
		std::sort(bry, bry+m);
		for (i=0, j=0, last=-1, ans=0; i<n; i++)
		{
			for (; j+1<m&&bry[j+1]<=ary[i]; j++);
			t = j;
			if (j+1 < m && ary[i] - bry[j] > bry[j+1] - ary[i])
			{
				t = j+1;
			}
			if (t == last)
			{
				++ans;
			}
			last = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
