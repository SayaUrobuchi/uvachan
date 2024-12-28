#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		s[i] = 'x';
	}
	puts(s);
	return 0;
}
