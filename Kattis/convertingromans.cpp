#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

int tbl[128];
char buf[300005];

int main()
{
	int count, i;
	vector<pp> stk;
	tbl['I'] = 1;
	tbl['V'] = 5;
	tbl['X'] = 10;
	tbl['L'] = 50;
	tbl['C'] = 100;
	tbl['D'] = 500;
	tbl['M'] = 1000;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		stk.clear();
		for (i=0; buf[i]; i++)
		{
			int d = tbl[buf[i]];
			int t = 0;
			while (!stk.empty()&&stk.back().first<d)
			{
				t += stk.back().first + stk.back().second;
				stk.pop_back();
			}
			stk.emplace_back(d, t);
		}
		int ans = 0;
		for (i=0; i<stk.size(); i++)
		{
			ans += stk[i].first - stk[i].second;
		}
		printf("%d\n", ans);
	}
	return 0;
}
