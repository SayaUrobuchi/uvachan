#include <iostream>

char s[1048576];

int main()
{
	char *cmd;
	std::string t;
	std::string::iterator p;
	while (scanf("%s", s) == 1)
	{
		cmd = s;
		t.clear();
		p = t.end();
		while (*cmd)
		{
			if (*cmd == 'R')
			{
				++p;
			}
			else if (*cmd == 'L')
			{
				--p;
			}
			else if (*cmd == 'B')
			{
				p = t.erase(p-1);
			}
			else
			{
				p = t.insert(p, *cmd)+1;
			}
			++cmd;
		}
		puts(t.c_str());
	}
	return 0;
}
