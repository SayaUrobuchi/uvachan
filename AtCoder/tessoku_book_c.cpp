#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=0; j<n; j++)
		{
			ans += (t + ary[j] == m);
		}
	}
	puts(ans ? "Yes" : "No");
	return 0;
}
