#include <stdio.h>
#include <math.h>

int main()
{
	int n, m, msqrt, i, j, k, num, ans, ans2;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m) break;
		msqrt = sqrt(m) + 1;
		for(i=2; i<msqrt; i++)
		{
			if(!(m % i))
			{
				for(num=0, j=1; j<m; j*=i, num++);
				if(j == m)
				{
					for(k=0, j=1; k<num; k++, j*=i+1);
					if(j == n)
					{
						break;
					}
				}
			}
		}
		if(i == msqrt)
		{
      for(j=1, num=0; j<n; j*=m+1, num++);
      i = m;
		}
		for(j=1, k=0, ans=0, ans2=0; k<num; j*=i, k++, n/=i+1)
		{
			ans += j;
			ans2 += j * n;
		}
		ans2 += j * n;
		printf("%d %d\n", ans, ans2);
	}
	return 0;
}
