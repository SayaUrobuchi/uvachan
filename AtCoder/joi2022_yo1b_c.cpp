#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	for (i=0; i+1<n; i++)
	{
		if (s[i+1] == 'J')
		{
			printf("%c\n", s[i]);
		}
	}
	return 0;
}
