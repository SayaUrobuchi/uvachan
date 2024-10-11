#include <iostream>
using namespace std;

const int N = 5005;
const int M = 998244353;

int p[N], v[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &p[i], &v[i]);
	}
	int ans = 1;
	for (i=0; i<m&&ans; i++)
	{
		bool l = true, r = true;
		for (j=0; j<i&&(l||r); j++)
		{
			if (p[j] <= p[i] && v[j] > v[i])
			{
				l = false;
			}
			if (p[j] >= p[i] && v[j] > v[i])
			{
				r = false;
			}
		}
		for (j=i+1; j<m&&(l||r); j++)
		{
			if (p[j] <= p[i] && v[j] < v[i])
			{
				l = false;
			}
			if (p[j] >= p[i] && v[j] < v[i])
			{
				r = false;
			}
		}
		ans = (ans * (l+r)) % M;
	}
	printf("%d\n", ans);
	return 0;
}
