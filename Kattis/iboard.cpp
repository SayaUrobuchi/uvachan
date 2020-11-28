#include <iostream>
using namespace std;

int main()
{
	int i, j, k, a, b;
	string s;
	while (getline(cin, s))
	{
		for (i=0, a=0, b=0; s[i]; i++)
		{
			for (j=s[i], k=0; k<7; k++, j>>=1)
			{
				if (j&1)
				{
					a = 1-a;
				}
				else
				{
					b = 1-b;
				}
			}
		}
		puts((a||b)?"trapped":"free");
	}
	return 0;
}
