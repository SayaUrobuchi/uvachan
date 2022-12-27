#include <iostream>
using namespace std;

int main()
{
	int i, t, u;
	char buf[128];
	while (scanf("%s", buf) == 1)
	{
		for (i=1, t=u=0; buf[i]; i++)
		{
			if (buf[i] != buf[i-1])
			{
				t = 1;
			}
			if ((buf[i]-'0'+9)%10+'0' != buf[i-1])
			{
				u = 1;
			}
		}
		if (!t || !u)
		{
			puts("Weak");
		}
		else
		{
			puts("Strong");
		}
	}
	return 0;
}

