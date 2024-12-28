#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (i=n-1, j=0; j<m; i--)
	{
		if (s[i] == '@')
		{
			s[i] = '.';
			++j;
		}
	}
	puts(s);
	return 0;
}
