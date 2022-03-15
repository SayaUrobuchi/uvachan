#include <iostream>
using namespace std;

int main()
{
	int a, b;
	const char *s;
	while (scanf("%d.%d", &a, &b) == 2)
	{
		s = "";
		if (b <= 2)
		{
			s = "-";
		}
		else if (b >= 7)
		{
			s = "+";
		}
		printf("%d%s\n", a, s);
	}
	return 0;
}
