#include <iostream>
using namespace std;

const int N = 512;

int px[N], py[N];

int main()
{
	int n, i, j, k, ans;
	scanf("%d", &n);
	for (i=0, ans=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			for (k=0; k<j; k++)
			{
				ans += ((long long)(px[i]-px[j])*(py[i]-py[k]) != (long long)(px[i]-px[k])*(py[i]-py[j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
