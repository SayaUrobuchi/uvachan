#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, i;
	string s;
	while (cin >> n)
	{
		getline(cin, s);
		getline(cin, s);
		for (i=0; s[i]; i++)
		{
			if ((s[i] >= '!' && s[i] <= '*') || (s[i] >= '[' && s[i] <= ']'))
			{
				cout << setw((1<<n)-1) << setfill('\\') << "";
			}
			cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}
