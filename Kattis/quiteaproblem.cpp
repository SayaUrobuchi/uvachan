#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int i;
	string s;
	while (getline(cin, s))
	{
		for (i=0; i<s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] |= 32;
			}
		}
		puts(strstr(s.c_str(), "problem")?"yes":"no");
	}
}
