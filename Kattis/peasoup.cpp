#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, st;
	bool first;
	string s, nam;
	while (cin >> n)
	{
		for (i=0, first=true; i<n; i++)
		{
			cin >> m;
			getline(cin, s);
			getline(cin, nam);
			for (j=0, st=0; j<m; j++)
			{
				getline(cin, s);
				if (s == "pea soup")
				{
					st |= 1;
				}
				else if (s == "pancakes")
				{
					st |= 2;
				}
			}
			if (st == 3 && first)
			{
				first = false;
				cout << nam;
			}
		}
		if (first)
		{
			cout << "Anywhere is fine I guess";
		}
		cout << "\n";
	}
	return 0;
}
