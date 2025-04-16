#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 128;

int ary[N], rnk[N];
pp bry[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		bry[i] = make_pair(ary[i], i);
	}
	sort(bry, bry+n);
	for (i=0; i<n; i=j)
	{
		for (j=i; j<n&&bry[i].first==bry[j].first; j++)
		{
			rnk[bry[j].second] = i + 1;
		}
	}
	for (i=0; i<n; i++)
	{
		printf("%d\n", rnk[i]);
	}
	return 0;
}
