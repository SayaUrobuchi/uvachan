#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, i;
	long long last;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		sort(ary, ary+n);
		for (i=0, last=0; i<n; i++)
		{
			if (ary[i] <= last+1)
			{
				last += ary[i];
			}
			else
			{
				break;
			}
		}
		cout << last+1 << "\n";
	}
	return 0;
}

