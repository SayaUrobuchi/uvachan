#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 200005;

pp ary[N];
int bry[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	sort(ary, ary+n);
	for (i=0; i<n; i++)
	{
		bry[ary[i].second] = -1;
		if (i > 0 && ary[i-1].first == ary[i].first)
		{
			bry[ary[i].second] = ary[i-1].second + 1;
		}
	}
	for (i=0; i<n; i++)
	{
		printf("%d%c", bry[i], " \n"[i+1==n]);
	}
	return 0;
}
