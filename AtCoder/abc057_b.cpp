#include <iostream>
using namespace std;

const int N = 55;
const int M = 55;

int px[N], py[N];
int qx[M], qy[M];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &qx[i], &qy[i]);
	}
	for (i=0; i<n; i++)
	{
		int d = 1e9;
		int id = 0;
		for (j=0; j<m; j++)
		{
			int t = abs(px[i]-qx[j]) + abs(py[i]-qy[j]);
			if (t < d)
			{
				d = t;
				id = j;
			}
		}
		printf("%d\n", id+1);
	}
	return 0;
}
