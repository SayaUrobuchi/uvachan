#include <iostream>
using namespace std;

int x[128], y[128];

int main()
{
	int count, n, i;
	long long ans;
	cin >> count;
	while (count--)
	{
		cin >> n;
		for (i=0; i<n; i++)
		{
			cin >> x[i] >> y[i];
		}
		x[n] = x[0];
		y[n] = y[0];
		for (i=0, ans=0; i<n; i++)
		{
			ans += x[i]*y[i+1] - x[i+1]*y[i];
		}
		cout << ans/2.0 << "\n";
	}
	return 0;
}
