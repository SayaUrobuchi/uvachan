#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int n;
int si[805], six[805], siy[805];
double ang, pi;
double px[805], py[805], pr[805], list[1705], sx[805], sy[805];
vector<int> vv[1705];

int comp(const void *p, const void *q)
{
	return *(double*)p > *(double*)q ? 1 : -1;
}

int comp2(const void *p, const void *q)
{
	return six[*(int*)p] - six[*(int*)q];
}

int equal(double x, double y)
{
	return fabs(x-y) < 1e-8;
}

void trans()
{
	int i;
	double a, b;
	for(i=0; i<n; i++)
	{
		if(equal(ang, 0))
		{
			a = py[i];
			b = pr[i];
		}
		else
		{
			a = px[i]-py[i]/tan(ang);
			b = pr[i]*sin(ang);
		}
		if(a+b > a-b)
		{
			sx[i] = a-b;
			sy[i] = a+b;
		}
		else
		{
			sx[i] = a+b;
			sy[i] = a-b;
		}
	}
}

int bisearch(int p, int q, double tar)
{
	int c;
	for(; p<=q; )
	{
		c = ((p+q)>>1);
		if(equal(list[c], tar))
		{
			return c;
		}
		else if(list[c] > tar)
		{
			q = c-1;
		}
		else
		{
			p = c+1;
		}
	}
	return -1;
}

int main()
{
	int i, j, k, ln, rat, ans, cnt, mx, tmx;
	double aang, aloc;
	srand(5566);
	rat = 2300;
	pi = 2.0 * acos(0.0);
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf%lf", &px[i], &py[i], &pr[i]);
		}
		for(k=0, ans=0; k<rat; k++)
		{
			ang = (rand()*rand()+rand())%31415926/10000000.0;
			trans();
			for(i=0, j=0; i<n; i++)
			{
				list[j++] = sx[i];
				list[j++] = sy[i];
			}
			qsort(list, j, sizeof(double), comp);
			for(i=1, ln=j, j=1; i<ln; i++)
			{
				if(!equal(list[i], list[i-1]))
				{
					list[j++] = list[i];
				}
			}
			ln = j;
			for(i=0; i<n; i++)
			{
				si[i] = i;
				six[i] = bisearch(0, ln-1, sx[i]);
				siy[i] = bisearch(0, ln-1, sy[i]);
			}
			qsort(si, n, sizeof(int), comp2);
			for(i=0, j=0, cnt=0, mx=0; i<ln; i++)
			{
				for(; j<n; j++)
				{
					if(six[si[j]] != i)
					{
						break;
					}
					cnt++;
					vv[siy[si[j]]].push_back(j);
				}
				if(cnt > mx)
				{
					mx = cnt;
					tmx = i;
				}
				while(vv[i].size())
				{
					vv[i].pop_back();
					cnt--;
				}
			}
			if(mx > ans)
			{
				ans = mx;
				aang = ang;
				aloc = list[tmx];
			}
		}
		printf("%d\n", ans);
		printf("%g %g %g\n", tan(aang), -1.0, tan(aang)*aloc);
	}
	return 0;
}
