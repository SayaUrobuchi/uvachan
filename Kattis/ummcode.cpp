#include <iostream>
using namespace std;

int main()
{
	int i, j;
	int tbl[128];
	string s, word, umm;
	char c;
	bool is_umm;
	tbl['u'] = 1;
	tbl['m'] = 0;
	getline(cin, s);
	s += " ";
	for (i=0, is_umm=true; i<s.size(); i++)
	{
		if (s[i] != ' ')
		{
			if (s[i] == 'u' || s[i] == 'm')
			{
				word += s[i];
			}
			else if (  (s[i] >= 'a' && s[i] <= 'z')
					|| (s[i] >= 'A' && s[i] <= 'Z')
					|| (s[i] >= '0' && s[i] <= '9'))
			{
				is_umm = false;
			}
		}
		else
		{
			if (word.size() && is_umm)
			{
				umm += word;
			}
			is_umm = true;
			word.clear();
		}
	}
	for (i=0; i<umm.size(); i+=7)
	{
		for (j=0, c=0; j<7; j++)
		{
			c = (c<<1) | (tbl[umm[i+j]]);
		}
		putchar(c);
	}
	puts("");
	return 0;
}