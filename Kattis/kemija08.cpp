#include <iostream>

int tbl[128];

int main()
{
	int i;
	tbl['a'] = tbl['e'] = tbl['i'] = tbl['o'] = tbl['u'] = 1;
	std::string s, t;
	while (std::getline(std::cin, s))
	{
		t = "";
		for (i=0; i<s.size(); i++)
		{
			t += s[i];
			if (tbl[s[i]])
			{
				i += 2;
			}
		}
		std::cout << t << "\n";
	}
	return 0;
}
