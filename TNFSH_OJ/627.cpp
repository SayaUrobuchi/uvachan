#include <iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, i, a, b;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		cin >> m;
		for (i=0; i<m; i++)
		{
			cin >> a >> b;
			cout << ary[((a+b)>>1)-1] << "\n";
		}
	}
	return 0;
}
