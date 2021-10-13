#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, i, t, sum, ans;
	set<int> se;
	while (cin >> n >> k)
	{
		se.clear();
		for (i=1, ans=0, sum=0; i<=n; i++)
		{
			cin >> t;
			sum = (sum + t) % k;
			ans = max(ans, sum);
			set<int>::iterator it = se.upper_bound(k-1-sum);
			if (it != se.begin())
			{
				--it;
				ans = max(ans, sum+*it);
			}
			se.insert((-sum+k)%k);
		}
		cout << ans << "\n";
	}
	return 0;
}
