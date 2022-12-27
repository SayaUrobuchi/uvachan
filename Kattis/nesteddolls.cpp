#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[100005];
int bry[100005];

int main()
{
	int count, n, i, j, k, sn;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first, &ary[i].second);
			ary[i].first = -ary[i].first;
		}
		sort(ary, ary+n);
		for (i=0, sn=0; i<n; i=j)
		{
			for (j=i, k=0; j<n&&ary[i].first==ary[j].first; j++, k++)
			{
				//for (; k<sn&&bry[k]<=ary[j].second; k++);
				k = upper_bound(bry+k, bry+sn, ary[j].second) - bry;
				bry[k] = ary[j].second;
				if (k == sn)
				{
					++sn;
				}
			}
		}
		printf("%d\n", sn);
	}
	return 0;
}