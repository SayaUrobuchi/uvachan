#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	printf("2");
	for (i=3; i<=n; i+=2)
	{
		bool is_p = true;
		for (j=2; j*j<=i&&is_p; j++)
		{
			if (i % j == 0)
			{
				is_p = false;
			}
		}
		if (is_p)
		{
			printf(" %d", i);
		}
	}
	puts("");
	return 0;
}
