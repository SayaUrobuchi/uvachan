#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b, t;
	double u;
	string s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	u = t = 0;
	while (cin >> s)
	{
		if (s == "buy")
		{
			cin >> a >> b;
			t += a;
			u += b*a;
		}
		else if (s == "sell")
		{
			cin >> a >> b;
			u -= a * (u/t);
			t -= a;
			if (t == 0)
			{
				u = 0;
			}
		}
		else if (s == "split")
		{
			cin >> a;
			t *= a;
		}
		else if (s == "merge")
		{
			cin >> a;
			u -= (t%a) * (u/t);
			t /= a;
			if (t == 0)
			{
				u = 0;
			}
		}
		else
		{
			cin >> a;
			cout << fixed << setprecision(10) << t*(a-max(0.0, (a-u/t))*0.3) << "\n";
			u = t = 0;
		}
	}
	return 0;
}
