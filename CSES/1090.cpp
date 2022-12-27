#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i, j, ans;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		sort(ary, ary+n);
		for (i=0, j=n-1, ans=0; i<=j; i++, ans++)
		{
			for (; j>i&&ary[i]+ary[j]>m; j--, ans++);
			j--;
		}
		cout << ans << "\n";
	}
	return 0;
}

