#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int n, i;
		scanf("%d", &n);
		vector<int> stk;
		for (i=1; i<=n; i++)
		{
			int t;
			scanf("%d", &t);
			if (t <= i)
			{
				while (stk.size() && t <= stk.back())
				{
					stk.pop_back();
				}
				stk.emplace_back(t);
			}
		}
		printf("%llu\n", stk.size());
	}
	return 0;
}
