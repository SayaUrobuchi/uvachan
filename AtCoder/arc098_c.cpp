#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 2048;

int ary[N];
pp bry[N];

int main()
{
	int n, m, o, i, j, k;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		bry[i] = make_pair(ary[i], i);
	}
	sort(bry, bry+n);
	set<int> se;
	se.emplace(-1);
	se.emplace(n);
	int best = 2e9;
	for (i=0; i<n; i=j)
	{
		vector<int> main_q;
		decltype(se)::iterator it, iu;
		it = se.begin();
		for (iu=it, ++iu; iu!=se.end(); ++it, ++iu)
		{
			int len = *iu - *it - 1;
			if (len >= m)
			{
				vector<int> v;
				for (k=*it+1; k<*iu; k++)
				{
					v.emplace_back(ary[k]);
				}
				sort(v.begin(), v.end());
				for (k=0; k<len-m+1; k++)
				{
					main_q.emplace_back(v[k]);
				}
			}
		}
		if (main_q.size() < o)
		{
			break;
		}
		sort(main_q.begin(), main_q.end());
		int least = main_q[0];
		int most = main_q[o-1];
		best = min(best, most-least);
		for (j=i; j<n&&bry[i].first==bry[j].first; j++)
		{
			se.emplace(bry[j].second);
		}
	}
	printf("%d\n", best);
	return 0;
}
