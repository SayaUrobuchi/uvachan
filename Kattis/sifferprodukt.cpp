#include <iostream>
using namespace std;

int main()
{
	int n, t;
	while (cin >> n)
	{
		while (n >= 10)
		{
			for (t=1; n; n/=10)
			{
				if (n%10)
				{
					t *= n%10;
				}
			}
			n = t;
		}
		cout << n << "\n";
	}
	return 0;
}
