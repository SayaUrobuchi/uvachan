#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j;
	char buf[8];
	scanf("%d%d", &n, &m);
	for (i=0, j=0; i<n*m; i++)
	{
		scanf("%1s", buf);
		if (isalpha(*buf))
		{
			putchar(*buf);
		}
	}
	return 0;
}
