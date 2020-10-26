#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int best, t;
	string ans, s;
	bool same;
	unordered_map<string, int> tbl;
	best = 0;
	same = false;
	while (getline(cin, s))
	{
		if (s == "***")
		{
			break;
		}
		t = ++tbl[s];
		if (t > best)
		{
			best = t;
			ans = s;
			same = false;
		}
		else if (t == best)
		{
			same = true;
		}
	}
	if (same)
	{
		cout << "Runoff!\n";
	}
	else
	{
		cout << ans << "\n";
	}
	return 0;
}
