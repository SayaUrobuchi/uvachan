#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, m, i;
	scanf("%d%d%s", &n, &m, s);
	int cnt = 0;
	for (i=0; i<n; i++)
	{
		if (s[i] == 'o')
		{
			++cnt;
			if (cnt > m)
			{
				s[i] = 'x';
			}
		}
	}
	puts(s);
	return 0;
}
