#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-8;

int d;

struct dat
{
	int x, y;
};

vector<dat> v;

double getdis(dat &t)
{
	return sqrt(t.x*t.x + t.y*t.y);
}

double getang(dat &t)
{
	return atan2(t.x, t.y);
}

bool comp(dat &p, dat &q)
{
	double dis, bang, ang, ang2;
	dis = getdis(p);
	bang = getang(p);
	ang = asin(d/dis) + bang;
	dis = getdis(q);
	bang = getang(q);
	ang2 = asin(d/dis) + bang;
	return ang < ang2;
}

int main()
{
	int count, n, i, j, k, best, id, t;
	double dis, bang, ang, ang2;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &d);
		v.resize(n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &v[i].x, &v[i].y);
		}
		std::sort(v.begin(), v.end(), comp);
		for (i=0, best=n; i<n; i++)
		{
			for (j=0, t=0; j<n; j=k, t++)
			{
				id = (i+j) % n;
				dis = getdis(v[id]);
				bang = getang(v[id]);
				ang = asin(d/dis) + bang;
				//printf("build ang: %.10lf\n", ang/PI*180);
				for (k=j+1; k<n; k++)
				{
					id = (i+k) % n;
					ang2 = getang(v[id]);
					dis = sin(ang2-ang) * getdis(v[id]);
					//printf("!? dis: %.10lf\n", dis);
					if (std::abs(dis) > d + EPS)
					{
						break;
					}
				}
				//printf("pack %d\n", k-j);
			}
			//printf("find %d from %d\n", t, i);
			if (t < best)
			{
				best = t;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
