#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	char a, b;
	scanf("%d %c %c%s", &n, &a, &b, s);
	for (i=0; i<n; i++)
	{
		if (s[i] != a)
		{
			s[i] = b;
		}
	}
	puts(s);
	return 0;
}
