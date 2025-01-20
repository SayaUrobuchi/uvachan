#include <iostream>
using namespace std;

const int N = 128;

char trans[128], s[N];

int main()
{
	int i;
	trans['9'] = '1';
	trans['1'] = '9';
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		s[i] = trans[s[i]];
	}
	puts(s);
	return 0;
}
