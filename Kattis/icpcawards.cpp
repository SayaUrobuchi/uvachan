#include <iostream>
#include <map>

std::map<std::string, int> tbl;

int main()
{
	int n, i, c;
	std::string s, t;
	while (std::cin >> n)
	{
		tbl.clear();
		for (i=0, c=12; i<n; i++)
		{
			std::cin >> s >> t;
			if (c && !tbl[s])
			{
				std::cout << s << " " << t << "\n";
				tbl[s] = 1;
				c--;
			}
		}
	}
	return 0;
}