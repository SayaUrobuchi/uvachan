#include <iostream>
using namespace std;

const int N = 128;

char s[N], t[N];

int main()
{
	int i, j;
	scanf("%s%s", s, t);
	for (i=0, j=0; s[i]||t[j]; )
	{
		if (!t[j] || (s[i] && s[i] <= t[j]))
		{
			putchar(s[i]);
			++i;
		}
		else
		{
			putchar(t[j]);
			++j;
		}
	}
	puts("");
	return 0;
}
