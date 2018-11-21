#include <stdio.h>

int tbl1[25], tbl2[25];

int main()
{
	int count, i, j, k, l, u, v, n, m, o, r, s, w, x, y, mx, ans;
	int *p, *q, *t;
	double loc;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		p = tbl1;
		q = tbl2;
		for(i=0, ans=0, mx=0; i<n; i++)
		{
			scanf("%d", &r);
			for(j=0; j<r; j++)
			{
				scanf("%d", &p[j]);
			}
			if(i)
			{
				for(j=0, mx=m; j<r; j++)
				{
					for(k=0; k<s; k++)
					{
						u = j-k;
						if(u < 0)
						{
							u = -u;
						}
						v = m-p[j]-q[k];
						if(v*v+u*u > o*o)
						{
							continue;
						}
						if(k > j)
						{
							w = j;
							x = k;
						}
						else
						{
							w = k;
							x = j;
						}
						for(l=w+1; l<x; l++)
						{
							y = l-k;
							if(y < 0)
							{
								y = -y;
							}
							loc = q[k]+(double)y*v/u;
							if((l < s && loc <= q[l]) || (l < r && loc >= m-p[l]))
							{
								break;
							}
						}
						if(l >= x && mx > p[j]+q[k])
						{
							mx = p[j]+q[k];
						}
					}
				}
			}
			s = r;
			t = p;
			p = q;
			q = t;
			ans += mx;
		}
		printf("%d\n", ans);
	}
	return 0;
}
