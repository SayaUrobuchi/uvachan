#include <iostream>
using namespace std;

char ext[1024];

bool is_p(int t)
{
	int i;
	for (i=2; (long long)i*i<=t; i++)
	{
		if (t % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=(n<<1)+1; !is_p(i); i++);
		*ext = 0;
		if (!is_p(n))
		{
			sprintf(ext, " (%d is not prime)", n);
		}
		printf("%d%s\n", i, ext);
	}
	return 0;
}
