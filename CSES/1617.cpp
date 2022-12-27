#include <iostream>
using namespace std;

const int M = 1000000007;

int main()
{
	int n;
	long long ans, t;
	while (cin >> n)
	{
		for (t=2, ans=1; n; n>>=1, t=(t*t)%M)
		{
			if (n & 1)
			{
				ans = (ans*t) % M;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

