#include <stdio.h>

int ary[1000005], m, ans;

int main()
{
	int n, i, j, max, min, left, right, center;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, max=-2147483647, min=2147483647; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(ary[i] > max)
			{
				max = ary[i];
			}
			if(ary[i] < min)
			{
				min = ary[i];
			}
		}
		for(left=min, right=max; left<=right; )
		{
			center = ((left + right) >> 1);
			for(i=0, j=0; i<n; i++)
			{
				if(center < ary[i])
				{
					j++;
					if(j >= m)
					{
						break;
					}
				}
			}
			if(j == m-1)
			{
				ans = center;
				break;
			}
			if(j < m)
			{
				ans = center;
				right = center - 1;
			}
			else
			{
				left = center + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
