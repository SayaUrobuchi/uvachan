#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (!next_permutation(s.begin(), s.end()))
		{
			cout << "0\n";
		}
		else
		{
			cout << s << "\n";
		}
	}
	return 0;
}
