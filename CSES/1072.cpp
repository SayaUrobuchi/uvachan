#include <iostream>
using namespace std;

int tbl[] = {0, 0, 6, 28, 96};
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};

int main()
{
	int n, i, t, u;
	long long ans;
	while (cin >> n)
	{
		for (i=1; i<=n; i++)
		{
			if (i <= 4)
			{
				cout << tbl[i] << "\n";
				continue;
			}
			ans = 0;
			ans += ((i*i-1-2) << 2);
			ans += ((i*i-1-3) << 3);
			ans += ((i*i-1-4) << 2);
			ans += ((i*i-1-4) << 2) * (long long)(i-4);
			ans += ((i*i-1-6) << 2) * (long long)(i-4);
			t = max(0, i-4);
			u = max(0, i*i-1-8);
			ans += (long long)t*t*u;
			cout << (ans>>1) << "\n";
		}
	}
	return 0;
}

