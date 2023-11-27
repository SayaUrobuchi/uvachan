#include <iostream>
using namespace std;

const int N = 10;
const int M = (1<<N);

char str[N][M];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	sprintf(str[0], "{}");
	for (i=1; i<=n; i++)
	{
		int p = 0;
		p += sprintf(str[i]+p, "{");
		for (j=0; j<i; j++)
		{
			if (j)
			{
				p += sprintf(str[i]+p, ",");
			}
			p += sprintf(str[i]+p, "%s", str[j]);
		}
		p += sprintf(str[i]+p, "}");
	}
	puts(str[n]);
	return 0;
}
