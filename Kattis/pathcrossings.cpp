#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 200005;
const int MAX_DIS = 1000000;

int idx[N], pl[N], px[N], py[N], pt[N];

bool comp(int a, int b)
{
	return pt[a] < pt[b];
}

int get_dis(int dx, int dy)
{
	return dx*dx + dy*dy;
}

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d%d", &pl[i], &px[i], &py[i], &pt[i]);
		idx[i] = i;
	}
	sort(idx, idx+m, comp);
	set<pair<int, int> > se;
	for (i=0; i<m; i++)
	{
		for (j=i+1; j<m&&pt[idx[j]]<=pt[idx[i]]+10; j++)
		{
			int dis = get_dis(px[idx[i]]-px[idx[j]], py[idx[i]]-py[idx[j]]);
			if (dis <= MAX_DIS)
			{
				int a = pl[idx[i]];
				int b = pl[idx[j]];
				if (a != b)
				{
					if (a > b)
					{
						swap(a, b);
					}
					se.emplace(a, b);
				}
			}
		}
	}
	printf("%llu\n", se.size());
	for (decltype(se)::iterator it = se.begin(); it!=se.end(); ++it)
	{
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}
