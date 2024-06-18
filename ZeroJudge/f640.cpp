#include <iostream>
using namespace std;

int rec()
{
	string s;
	cin >> s;
	if (s == "f")
	{
		int x = rec();
		return 2 * x - 3;
	}
	else if (s == "g")
	{
		int x = rec();
		int y = rec();
		return 2 * x + y - 7;
	}
	else if (s == "h")
	{
		int x = rec();
		int y = rec();
		int z = rec();
		return 3 * x - 2 * y + z;
	}
	return stol(s);
}

int main()
{
	cout << rec() << "\n";
	return 0;
}