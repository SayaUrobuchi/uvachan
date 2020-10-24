#include <iostream>

int sn, stk[1048576];

int main()
{
	int n, i;
	std::string s;
	while (scanf("%d", &n) == 1)
	{
		std::getline(std::cin, s);
		std::getline(std::cin, s);
		sn = 0;
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				stk[sn] = s[i];
				++sn;
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (sn == 0 || std::abs(stk[sn-1] - s[i]) > 2)
				{
					break;
				}
				--sn;
			}
		}
		if (i < s.size())
		{
			printf("%c %d\n", s[i], i);
		}
		else
		{
			puts("ok so far");
		}
	}
	return 0;
}
