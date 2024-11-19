#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

char s[N];
pair<int, int> ary[N];

int main()
{
	int n, i, j;
	scanf("%d%s", &n, s);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
		if (s[i] == '1')
		{
			++ans;
		}
	}
	sort(ary, ary+n);
	int best = ans;
	for (i=0; i<n; i=j)
	{
		for (j=i; j<n&&ary[i].first==ary[j].first; j++)
		{
			if (s[ary[j].second] == '0')
			{
				++ans;
			}
			else
			{
				--ans;
			}
		}
		best = max(best, ans);
	}
	printf("%d\n", best);
	return 0;
}