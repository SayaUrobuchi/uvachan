#include <stdio.h>
#include <map>
#include <algorithm>

int ary[200005];

struct comp
{
	bool operator()( const int& p, const int& q ) const
	{
		return ary[p]!=ary[q] ? ary[p] < ary[q] : p < q;
	}
};

std::map<int, int, comp > tbl;

int main()
{
	int n, i, j, mx;
	long long k, sum;
	while (scanf("%d%lld", &n, &k) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		sum = 0;
		mx = -1;
		tbl.clear();
		for (i=0, j=0; i<n&&j<n; i++)
		{
			for (; j<n&&(tbl.size() == 0 || (tbl.rbegin())->second - tbl.begin()->second <= k); j++)
			{
				tbl.insert({j, ary[j]});
				sum += ary[j];
				if ((tbl.rbegin())->second - tbl.begin()->second <= k)
				{
					if (sum > mx)
					{
						//printf("%d => %d ==== k: %d, %d\n", i, sum, (tbl.rbegin())->second, tbl.begin()->second);
						mx = sum;
					}
				}
				else
				{
					tbl.erase(j);
					sum -= ary[j];
					break;
				}
			}
			//printf("%d => %d, %d\n", tbl.size(), tbl.begin()->second, tbl.rbegin()->second);
			//printf("uni %d %lld\n", j, sum);
			sum -= ary[i];
			tbl.erase(i);
		}
		printf("%lld\n", mx);
	}
	return 0;
}
