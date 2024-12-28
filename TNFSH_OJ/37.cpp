#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		int ans = 0;
		int t;
		while (ss >> t)
		{
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
