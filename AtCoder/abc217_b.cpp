#include <iostream>
using namespace std;

char a[8], b[8], c[8];

int main()
{
	while (scanf("%s%s%s", a, b, c) == 3)
	{
		printf("A%cC\n", (int)'B'+'G'+'R'+'H'-a[1]-b[1]-c[1]);
	}
	return 0;
}

