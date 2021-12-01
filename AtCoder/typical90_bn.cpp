#include <iostream>
using namespace std;

int ll[128], rr[128];

int main()
{
	int n, i, j, k, a, b;
	double t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &ll[i], &rr[i]);
			for (k=ll[i], t=0; k<=rr[i]; k++)
			{
				for (j=0; j<i; j++)
				{
					a = max(k+1, ll[j]);
					b = rr[j];
					if (b >= a)
					{
						t += (double)(b-a+1) / (rr[j]-ll[j]+1);
					}
				}
			}
			ans += t / (rr[i]-ll[i]+1);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
