#include <iostream>
using namespace std;

const int N = 32;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	bool all0 = true;
	for (i=1; i<16&&all0; i+=2)
	{
		if (s[i] != '0')
		{
			all0 = false;
		}
	}
	puts(all0 ? "Yes" : "No");
	return 0;
}
