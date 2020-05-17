#include <iostream>
#include <sstream>

std::string buf, s[1024];

int main()
{
	int i, j, rep;
	while (std::getline(std::cin, buf))
	{
		std::stringstream ss(buf);
		i = 0;
		rep = 0;
		while (ss >> s[i])
		{
			for (j=0; j<i&&!rep; j++)
			{
				if (s[i] == s[j])
				{
					rep = 1;
				}
			}
			i++;
		}
		std::cout << (rep ? "no" : "yes") << "\n";
	}
	return 0;
}
