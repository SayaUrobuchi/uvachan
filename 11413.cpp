#include <stdio.h>

int ary[1001];

int main()
{
	int n, m, i, j, left, right, center, cap, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, left=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(ary[i] > left)
			{
				left = ary[i];
			}
		}
		for(right=1000000001; left<=right; )
		{
			center = left + right;
			center /= 2;
			for(i=0, j=0, cap=0; i<n; i++)
			{
				if(cap + ary[i] <= center)
				{
					cap += ary[i];
				}
				else
				{
					j++;
					if(j == m)
					{
						break;
					}
					cap = ary[i];
				}
			}
			if(j == m)
			{
				left = center + 1;
			}
			else
			{
				ans = center;
				right = center - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
