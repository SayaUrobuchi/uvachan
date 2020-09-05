#include <iostream>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << "Thank you, " << s << ", and farewell!\n";
	}
	return 0;
}
