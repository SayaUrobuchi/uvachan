#include <iostream>
using namespace std;

char s[1005];

int main()
{
	int a, b, na, nb, i;
	scanf("%s", &s);
	for (i=0, a=0, b=1; s[i]; i++)
	{
		na = a;
		nb = b;
		if (s[i] != 'S')
		{
			na++;
		}
		if (s[i] != 'N')
		{
			nb++;
		}
		a = min(na, nb+1);
		b = min(nb, na+1);
	}
	printf("%d\n", min(a, b+1));
	return 0;
}