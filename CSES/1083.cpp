#include <iostream>
using namespace std;

int ucnt, used[262144];

int main()
{
	int n, i, t;
	while (cin >> n)
	{
		++ucnt;
		for (i=1; i<n; i++)
		{
			cin >> t;
			used[t] = ucnt;
		}
		for (i=1; i<=n; i++)
		{
			if (used[i] != ucnt)
			{
				break;
			}
		}
		cout << i << "\n";
	}
	return 0;
}

