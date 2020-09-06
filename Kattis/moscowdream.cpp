#include <iostream>
#include <algorithm>
using namespace std;

string str[1024];

int main()
{
	int cas, count, n, m, i;
	cas = 0;
	cin >> count;
	while (count--)
	{
		cin >> n >> m;
		for (i=0; i<n; i++)
		{
			cin >> str[i];
			reverse(str[i].begin(), str[i].end());
		}
		reverse(str, str+n);
		cout << "Test " << ++cas << "\n";
		for (i=0; i<n; i++)
		{
			cout << str[i] << "\n";
		}
	}
	return 0;
}
