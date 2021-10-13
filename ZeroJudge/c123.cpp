#include <iostream>
#include <stack>
using namespace std;

int ary[1024];

int main()
{
	int n, i, nxt;
	bool gg;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		while (cin >> ary[0])
		{
			if (ary[0] == 0)
			{
				break;
			}
			for (i=1; i<n; i++)
			{
				cin >> ary[i];
			}
			stack<int> stk;
			for (i=0, nxt=1, gg=false; i<n; i++)
			{
				if (ary[i] >= nxt)
				{
					for (; nxt<ary[i]; nxt++)
					{
						stk.push(nxt);
					}
					nxt++;
				}
				else if (stk.size() && ary[i] == stk.top())
				{
					stk.pop();
				}
				else
				{
					gg = true;
					break;
				}
			}
			if (gg)
			{
				cout << "No\n";
			}
			else
			{
				cout << "Yes\n";
			}
		}
		cout << "\n";
	}
	return 0;
}
