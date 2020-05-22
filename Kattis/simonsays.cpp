#include <stdio.h>
#include <iostream>
#include <string>

char buf[1048576];

int main()
{
	int n, i;
	std::string s;
	while (std::cin >> n)
	{
		std::getline(std::cin, s);
		for (i=0; i<n; i++)
		{
			std::getline(std::cin, s);
			if (sscanf(s.c_str(), "Simon says%[^\n]", buf) == 1)
			{
				puts(buf);
			}
		}
	}
	return 0;
}
