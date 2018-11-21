#include <stdio.h>

int ary[205][205];

double ab(double t)
{
	return t<0 ? -t : t;
}

int nles(double p, double q)
{
	return p<q || ab(p-q)<1e-10;
}

int main()
{
	int n, m, i, j, k, l, p, q, x1, y1, x2, y2, z1, max, lx, ly, cnt, ii, jj, xl, xr, yl, yr, hei;
	double temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for(i=0, max=0, hei=-1, lx=ly=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(ary[i][j] == 0)
				{
					continue;
				}
				cnt = 0;
				for(k=0; k<n; k++)
				{
					for(l=0; l<m; l++)
					{
						if(ary[k][l] == 0)
						{
							continue;
						}
						if(k != i || l != j)
						{
							if(k > i)
							{
								xl = i;
								xr = k;
								ii = 1;
							}
							else
							{
								xl = k;
								xr = i;
								ii = -1;
							}
							if(l > j)
							{
								yl = j;
								yr = l;
								jj = 1;
							}
							else
							{
								yl = l;
								yr = j;
								jj = -1;
							}
							for(p=i; p<=xr&&p>=xl; p+=ii)
							{
								for(q=j; q<=yr&&q>=yl; q+=jj)
								{
									if((p!=i||q!=j) && (p!=k||q!=l))
									{
										x1 = i-p;
										y1 = j-q;
										x2 = i-k;
										y2 = j-l;
										if(x1*y2 == x2*y1)
										{
											z1 = ary[k][l] - ary[i][j];
											temp = (x2?ary[i][j]+(double)z1*x1/x2:ary[i][j]+(double)z1*y1/y2);
											if(nles(temp, ary[p][q]))
											{
												break;
											}
										}
									}
								}
								if(q<=yr&&q>=yl)
								{
									break;
								}
							}
							if(!(p<=xr&&p>=xl))
							{
								cnt++;
							}
						}
					}
				}
				if(cnt > max)
				{
					max = cnt;
					hei = ary[i][j];
					lx = i+1;
					ly = j+1;
				}
				else if(cnt == max && hei < ary[i][j])
				{
					hei = ary[i][j];
					lx = i+1;
					ly = j+1;
				}
				else if(cnt == max && hei == ary[i][j])
				{
					lx = 0;
					ly = 0;
				}
			}
		}
		printf("%d %d %d\n", lx, ly, max);
	}
	return 0;
}
