#include <iostream>
using namespace std;

bool tbl[16];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		tbl[t] = true;
	}
	for (i=1, ans=0; i<=6; i++)
	{
		for (j=1; j<=6; j++)
		{
			if (tbl[i+j])
			{
				++ans;
			}
		}
	}
	printf("%.10lf\n", ans/36.);
	return 0;
}
