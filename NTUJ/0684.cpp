#include <stdio.h>

long long ab(long long t)
{
	return t<0 ? -t : t;
}

int main()
{
	int n, i, nx, ny, sx, sy, lx, ly;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &nx, &ny);
			if(i == 0)
			{
				sx = nx;
				sy = ny;
			}
			else
			{
				ans += (long long)lx * ny - (long long)nx * ly;
			}
			lx = nx;
			ly = ny;
		}
		ans += (long long)lx * sy - (long long)ny * sx;
		printf("%lld\n", ab(ans));
	}
	return 0;
}
