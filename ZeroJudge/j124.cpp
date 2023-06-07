#include <iostream>
using namespace std;

long long ans;

int dfs()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		return 0;
	}
	for (int i=0; i<2+(n%2); i++)
	{
		int a = dfs();
		if (a)
		{
			ans += abs(n-a);
		}
	}
	return n;
}

int main()
{
	ans = 0;
	dfs();
	cout << ans << "\n";
	return 0;
}
