#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[3];
	string s;
	while (cin >> a[0] >> a[1] >> a[2] >> s)
	{
		sort(a, a+3);
		cout << a[s[0]-'A'] << " " << a[s[1]-'A'] << " " << a[s[2]-'A'] << "\n";
	}
	return 0;
}
