#include <iostream>
using namespace std;

char buf[1024];

int main()
{
	int n, i, c;
	double rat;
	scanf("%*s%lf%d", &rat, &n);
	for (i=0, c=0; i<n; i++)
	{
		scanf("%s", buf);
		if (*buf == 'e')
		{
			++c;
			scanf("%*s");
		}
	}
	puts(n*rat>=c?"Jebb":"Neibb");
	return 0;
}
