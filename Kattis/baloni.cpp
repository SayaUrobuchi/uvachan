#include <iostream>
using namespace std;

const int N = 1000005;

int tbl[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (tbl[t] > 0)
		{
			--tbl[t];
		}
		else
		{
			++ans;
		}
		++tbl[t-1];
	}
	printf("%d\n", ans);
	return 0;
}