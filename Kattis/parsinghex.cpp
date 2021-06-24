#include <iostream>
using namespace std;

int main()
{
	int i, p;
	unsigned int t;
	string s;
	while (getline(cin, s))
	{
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '0')
			{
				if (i+1 < s.size() && (s[i+1] == 'x' || s[i+1] == 'X'))
				{
					if (sscanf(s.c_str()+i, "%x%n", &t, &p) == 1)
					{
						printf("%.*s %u\n", p, s.c_str()+i, t);
						i += p-1;
					}
				}
			}
		}
	}
	return 0;
}
