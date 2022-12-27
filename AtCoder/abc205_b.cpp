#include <iostream>
using namespace std;

int ucnt, used[1024];

int main()
{
	int n, i, t;
	bool gg;
	while (cin >> n)
	{
		++ucnt;
		for (i=0, gg=false; i<n; i++)
		{
			cin >> t;
			if (used[t] == ucnt)
			{
				gg = true;
			}
			used[t] = ucnt;
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
	return 0;
}
