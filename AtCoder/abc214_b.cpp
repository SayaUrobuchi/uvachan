#include <iostream>
using namespace std;

int main()
{
	int a, b, i, j, k, ans;
	while (scanf("%d%d", &a, &b) == 2)
	{
		for (i=0, ans=0; i<=a; i++)
		{
			for (j=0; j+i<=a; j++)
			{
				for (k=0; k+i+j<=a; k++)
				{
					if (i*j*k <= b)
					{
						++ans;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

