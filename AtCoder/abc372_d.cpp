#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 200005;

int ary[N], dif[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	ary[0] = 1e9;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	vector<pp> stk;
	for (i=n; i>=0; i--)
	{
		while (stk.size() && stk.back().first < ary[i])
		{
			++dif[i];
			--dif[stk.back().second];
			stk.pop_back();
		}
		stk.emplace_back(ary[i], i);
	}
	int cur = dif[0];
	for (i=1; i<=n; i++)
	{
		cur += dif[i];
		printf("%d%c", cur, " \n"[i==n]);
	}
	return 0;
}
