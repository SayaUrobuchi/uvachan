#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	int day, t;
	string s, nam;
	map<string, int> tbl, res;
	day = 0;
	while (cin >> s)
	{
		tbl.clear();
		res.clear();
		while (cin >> s)
		{
			if (s == "CLOSE")
			{
				break;
			}
			cin >> nam >> t;
			if (s == "ENTER")
			{
				tbl[nam] = t;
			}
			else
			{
				res[nam] += t-tbl[nam];
			}
		}
		if (day)
		{
			cout << "\n";
		}
		cout << "Day " << ++day << "\n";
		for (map<string, int>::iterator it=res.begin(); it!=res.end(); it++)
		{
			cout << it->first << " $" << fixed << setprecision(2) << it->second*0.1 << "\n";
		}
	}
	return 0;
}
