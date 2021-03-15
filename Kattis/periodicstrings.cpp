#include <iostream>

int main()
{
	int i, j, k, l;
	bool flag;
	std::string s;
	while (std::getline(std::cin, s))
	{
		for (i=1; i<s.size(); i++)
		{
			if (s.size() % i == 0)
			{
				for (j=i, k=i-1, flag=true; j<s.size()&&flag; j+=i, k+=i-1)
				{
					for (l=0; l<i&&flag; l++)
					{
						if (s[j+l] != s[(k+l)%i])
						{
							flag = false;
							break;
						}
					}
				}
				if (flag)
				{
					break;
				}
			}
		}
		printf("%d\n", i);
	}
	return 0;
}