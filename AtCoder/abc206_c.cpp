#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n, i, t;
	long long ans, sum;
	unordered_map<int, int> mp;
	while (cin >> n)
	{
		mp.clear();
		for (i=0; i<n; i++)
		{
			cin >> t;
			++mp[t];
		}
		ans = 0;
		sum = 0;
		for (auto it=mp.begin(); it!=mp.end(); ++it)
		{
			ans += sum * it->second;
			sum += it->second;
		}
		cout << ans << "\n";
	}
	return 0;
}
