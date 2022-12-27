#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, t;
	long long p, q, sum, ans;
	unordered_map<long long, int> mp;
	cin >> n >> p >> q;
	++mp[0];
	for (i=1, sum=0, ans=0; i<=n; i++)
	{
		cin >> t;
		sum += t;
		ans += mp[sum*q - p*i];
		++mp[sum*q - p*i];
	}
	cout << ans << "\n";
	return 0;
}