#include <stdio.h>
#include <math.h>

int parent[105], count[105];
double x[105], y[105], r[105];

int getparent(int n)
{
	if(parent[n])
	{
		return parent[n]=getparent(parent[n]);
	}
	return n;
}

double getdis(double p, double q)
{
	return sqrt(p*p+q*q);
}

int intersect(int p, int q)
{
	double d;
	d = getdis(x[p]-x[q], y[p]-y[q]);
	if(r[p] > d || r[q] > d)
	{
		if(r[p] < r[q])
		{
			return r[p] + d > r[q];
		}
		return r[q] + d > r[p];
	}
	return r[p] + r[q] > d;
}

int main()
{
	int n, i, j, p, q, res;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		for(i=1, res=n?1:0; i<=n; i++)
		{
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
			parent[i] = 0;
			count[i] = 1;
			for(j=1; j<i; j++)
			{
				if(intersect(i, j))
				{
					p = getparent(i);
					q = getparent(j);
					if(p != q)
					{
						parent[q] = p;
						count[p] += count[q];
						if(count[p] > res)
						{
							res = count[p];
						}
					}
				}
			}
		}
		if(res != 1)
		{
			printf("The largest component contains %d rings.\n", res);
		}
		else
		{
			printf("The largest component contains %d ring.\n", res);
		}
	}
	return 0;
}

