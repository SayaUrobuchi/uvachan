#include <iostream>
#include <cmath>
using namespace std;

const int N = 128;

int px[N], py[N], mid[N];
//double mx[N];
int mx[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			int dx = px[i] - px[j];
			int dy = py[i] - py[j];
			int d = (dx * dx) + (dy * dy);
			//double dd = sqrt(d);
			int dd = d;
			if (dd > mx[i])
			{
				mx[i] = dd;
				mid[i] = j;
			}
			if (dd > mx[j])
			{
				mx[j] = dd;
				mid[j] = i;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		printf("%d\n", mid[i]+1);
	}
	return 0;
}
