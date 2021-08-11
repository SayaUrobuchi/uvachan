#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, best;
bool first;
string str[128];

void print()
{
	int i;
	if (!n)
	{
		return;
	}
	sort(str, str+n);
	if (!first)
	{
		cout << "\n";
	}
	first = false;
	for (i=0; i<n; i++)
	{
		reverse(str[i].begin(), str[i].end());
		cout << setw(best) << str[i] << "\n";
	}
}

int main()
{
	first = true;
	n = 0;
	best = 0;
	while (getline(cin, str[n]))
	{
		if (str[n].size() == 0)
		{
			print();
			n = 0;
			best = 0;
		}
		else
		{
			best = max(best, (int)str[n].size());
			reverse(str[n].begin(), str[n].end());
			n++;
		}
	}
	print();
	return 0;
}
