#include <iostream>
#include <algorithm>
using namespace std;

string nam[1024];

bool comp(string p, string q)
{
	if (p[0] == q[0])
	{
		return p[1] < q[1];
	}
	return p[0] < q[0];
}

int main()
{
	int n, i;
	bool first;
	first = true;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			cin >> nam[i];
		}
		stable_sort(nam, nam+n, comp);
		if (!first)
		{
			cout << "\n";
		}
		for (i=0; i<n; i++)
		{
			cout << nam[i] << "\n";
		}
		first = false;
	}
	return 0;
}
