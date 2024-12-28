#include <iostream>
using namespace std;

int main()
{
	int i;
	char s[8];
	scanf("%s", s);
	for (i=0; i<3; i++)
	{
		putchar(s[(i+1)%3]);
	}
	puts("");
	return 0;
}
