#include <iostream>
using namespace std;

const int N = 128;

char key[N], s[N];

int main()
{
	int n, i, j;
	scanf("%s%d", key, &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		for (j=0; s[j]; j++)
		{
			int d = s[j] - 'A';
			d *= key[j] - '0';
			s[j] = (d % 26) + 'A';
		}
		puts(s);
	}
	return 0;
}
