#include <iostream>
using namespace std;

int n;
long long ans, sum;
int ary[32];

void dfs(int depth, long long total)
{
	ans = min(ans, abs(sum-total-total));
	if (depth == n)
	{
		return;
	}
	dfs(depth+1, total);
	dfs(depth+1, total+ary[depth]);
}

int main()
{
	int i;
	while (cin >> n)
	{
		for (i=0, sum=0; i<n; i++)
		{
			cin >> ary[i];
			sum += ary[i];
		}
		ans = sum;
		dfs(0, 0LL);
		cout << ans << "\n";
	}
	return 0;
}

