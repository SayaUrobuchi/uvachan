#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 100005;

pp ary[N], bry[N];

int main()
{
	int n, m, i, j, k, t, mm, ss;
	scanf("%d%d%*d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d.%d", &ary[i].first, &mm, &ss);
		t = mm*60 + ss;
		ary[i].second = t;
	}
	sort(ary, ary+n);
	for (i=0, k=0; i<n; i=j)
	{
		for (j=i+1, t=ary[i].second; j<n&&ary[i].first==ary[j].first; t+=ary[j].second, j++);
		if (j-i == m)
		{
			bry[k] = {t, ary[i].first};
			++k;
		}
	}
	sort(bry, bry+k);
	for (i=0; i<k; i++)
	{
		printf("%d\n", bry[i].second);
	}
	return 0;
}
