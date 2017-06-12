#include <stdio.h>
#include <math.h>

int main()
{
	int ans;
	long long n, i, j;
	long long ii, jj, temp;
	while(scanf("%lld", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		j = pow(n, 1.0/3) + 1e-10 + 1;
		for(i=1, ii=i*i*i, jj=j*j*j, ans=0; ; )
		{
			temp = jj - ii;
			if(temp == n)
			{
				ans = 1;
				break;
			}
			else if(temp > n)
			{
				if((i+1)*(i+1)*(i+1)-ii > n)
				{
					break;
				}
				i = pow(jj-n-1, 1.0/3) + 1e-10 + 1;
				ii = i * i * i;
			}
			else
			{
				j = pow(n+ii-1, 1.0/3) + 1e-10 + 1;
				jj = j * j * j;
			}
		}
		if(ans)
		{
			printf("%lld %lld\n", j, i);
		}
		else
		{
			printf("No solution\n");
		}
	}
	return 0;
}
