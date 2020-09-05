#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int d, r, g;
};

node ary[1024];

bool comp(node &p, node &q)
{
	return p.d < q.d;
}

int main()
{
	int n, m, i, d, t, ex, ans;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].d >> ary[i].r >> ary[i].g;
		}
		sort(ary, ary+n, comp);
		for (i=0, ex=0, d=0, ans=0; i<n; i++)
		{
			ans += ex + ary[i].d - d;
			t = ans % (ary[i].r + ary[i].g);
			ex = 0;
			if (t < ary[i].r)
			{
				ex = ary[i].r - t;
			}
			d = ary[i].d;
		}
		cout << ans + ex + m-d << "\n";
	}
	return 0;
}
