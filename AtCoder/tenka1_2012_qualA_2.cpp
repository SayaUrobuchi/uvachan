#include <iostream>
using namespace std;

int main()
{
	int i;
	string s, t;
	getline(cin, s);
	for (i=0; i<s.size(); i++)
	{
		if (s[i] == ' ')
		{
			if (!i || s[i-1] != ' ')
			{
				t += ',';
			}
		}
		else
		{
			t += s[i];
		}
	}
	puts(t.c_str());
	return 0;
}
