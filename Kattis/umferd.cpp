#include <iostream>
using namespace std;

char s[512];

int main()
{
	int n, m, i, j, empty;
	scanf("%d%d", &m, &n);
	for (i=0, empty=0; i<n; i++)
	{
		scanf("%s", s);
		for (j=0; s[j]; j++)
		{
			empty += (s[j] == '.');
		}
	}
	printf("%.6lf\n", empty*1./(n*m));
	return 0;
}
