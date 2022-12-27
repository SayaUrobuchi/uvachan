#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2];

int main()
{
	int n, i, j;
	while (cin >> n)
	{
		if ((n&3) == 1 || (n&3) == 2)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			v[0].clear();
			v[1].clear();
			for (i=n; i>=4; i-=4)
			{
				v[0].emplace_back(i);
				v[0].emplace_back(i-3);
				v[1].emplace_back(i-1);
				v[1].emplace_back(i-2);
			}
			if (i > 0)
			{
				v[0].emplace_back(i);
				v[1].emplace_back(i-1);
				v[1].emplace_back(i-2);
			}
			for (i=0; i<2; i++)
			{
				cout << v[i].size() << "\n" << v[i][0];
				for (j=1; j<v[i].size(); j++)
				{
					cout << " " << v[i][j];
				}
				cout << "\n";
			}
		}
	}
	return 0;
}

