#include <iostream>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "Hello,World!")
		{
			puts("AC");
		}
		else
		{
			puts("WA");
		}
	}
	return 0;
}

