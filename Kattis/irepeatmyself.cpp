#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int count, i, j;
	bool flag;
	string s;
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		for (i=1; i<=s.size(); i++)
		{
			for (j=i, flag=true; j<s.size(); j+=i)
			{
				if (strncmp(s.c_str(), s.c_str()+j, min(i, (int)s.size()-j)))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
