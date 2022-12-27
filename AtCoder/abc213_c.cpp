#include <iostream>
#include <algorithm>
using namespace std;

const int N = 131072;

int px[N], py[N], idx[N];
int ansx[N], ansy[N];

bool xcomp(int a, int b)
{
	return px[a] < px[b];
}

bool ycomp(int a, int b)
{
	return py[a] < py[b];
}

int main()
{
	int n, m, o, i, last, id;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<o; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			idx[i] = i;
		}
		sort(idx, idx+o, xcomp);
		for (i=0, last=-1, id=0; i<o; i++)
		{
			if (px[idx[i]] != last)
			{
				last = px[idx[i]];
				++id;
			}
			ansx[idx[i]] = id;
		}
		sort(idx, idx+o, ycomp);
		for (i=0, last=-1, id=0; i<o; i++)
		{
			if (py[idx[i]] != last)
			{
				last = py[idx[i]];
				++id;
			}
			ansy[idx[i]] = id;
		}
		for (i=0; i<o; i++)
		{
			printf("%d %d\n", ansx[i], ansy[i]);
		}
	}
	return 0;
}

