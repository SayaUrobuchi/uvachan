#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

const int N = 200005;

ppp ary[N];
pp bry[N];
int pre[N];

bool cmp(const pp &a, const pp &b)
{
	return a.second < b.second;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first.first, &ary[i].first.second);
		ary[i].second = i + 1;
	}
	sort(ary, ary+n);
	int len = -1;
	for (i=0; i<n; i++)
	{
		pp p = make_pair(ary[i].first.second, ary[i].second);
		for (; len>=0&&p<bry[len]; len--);
		bry[++len] = p;
	}
	++len;
	printf("%d\n", len);
	sort(bry, bry+len, cmp);
	for (i=0; i<len; i++)
	{
		printf("%d%c", bry[i].second, i+1<len?' ':'\n');
	}
	return 0;
}
