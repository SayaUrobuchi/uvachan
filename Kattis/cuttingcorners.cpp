#include <iostream>
#include <cmath>
using namespace std;

const int N = 32;
const double PI = acos(-1);
const double HALF = PI;
const double WHOLE = HALF * 2;

int px[N], py[N];

inline double get_ang(int i, int j, int k)
{
	double ang = atan2(py[i]-py[j], px[i]-px[j])
			   - atan2(py[k]-py[j], px[k]-px[j]);
	if (ang < 0)
	{
		ang += WHOLE;
	}
	if (ang > HALF)
	{
		ang = WHOLE - ang;
	}
	return ang;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		while (n > 3)
		{
			int worst_id;
			double worst;
			for (i=0, worst=WHOLE; i<n; i++)
			{
				double ang = get_ang((i+n-1)%n, i, (i+1)%n);
				if (ang < worst)
				{
					worst = ang;
					worst_id = i;
				}
			}
			double lang = get_ang((worst_id+n-2)%n, (worst_id+n-1)%n, (worst_id+1)%n);
			double rang = get_ang((worst_id+n-1)%n, (worst_id+1)%n, (worst_id+2)%n);
			if (lang < worst || rang < worst)
			{
				break;
			}
			--n;
			for (i=worst_id; i<n; i++)
			{
				px[i] = px[i+1];
				py[i] = py[i+1];
			}
		}
		printf("%d", n);
		for (i=0; i<n; i++)
		{
			printf(" %d %d", px[i], py[i]);
		}
		puts("");
	}
	return 0;
}
