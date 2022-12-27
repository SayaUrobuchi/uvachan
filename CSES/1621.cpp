#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, i, j, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		sort(ary, ary+n);
		for (i=0, ans=0; i<n; i=j)
		{
			for (j=i+1; j<n&&ary[j]==ary[i]; j++);
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}

