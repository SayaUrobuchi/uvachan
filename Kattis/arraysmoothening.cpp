#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N], bry[N];

int main()
{
	int n, m, i, j, k, last, amount, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, k=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[i]==ary[j]; j++);
		bry[k++] = j - i;
	}
	sort(bry, bry+k, greater<int>());
	bry[k++] = 0;
	for (i=1, last=bry[0], amount=1, ans=last; i<k&&m>0; i++)
	{
		int need = amount * (last - bry[i]);
		if (m >= need)
		{
			ans = bry[i];
			++amount;
			m -= need;
		}
		else
		{
			ans = last - (m / amount);
			m = 0;
		}
		last = bry[i];
	}
	printf("%d\n", ans);
	return 0;
}
