#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144], bry[262144];

int main()
{
	int n, m, o, i, j, ans;
	while (cin >> n >> m >> o)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		sort(ary, ary+n);
		for (i=0; i<m; i++)
		{
			cin >> bry[i];
		}
		sort(bry, bry+m);
		for (i=0, j=0, ans=0; i<n; i++)
		{
			for (; j<m&&bry[j]<ary[i]-o; j++);
			if (j < m && bry[j] <= ary[i]+o)
			{
				++ans;
				++j;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

