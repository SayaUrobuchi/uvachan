#include <iostream>
using namespace std;

int ary[131072];

int main()
{
	int n, i, j;
	long long sum, t;
	bool ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		ans = false;
		if (sum % 10 == 0)
		{
			for (i=0, j=0, t=0; i<n&&!ans; i++)
			{
				for (; t*10<sum; t+=ary[(j++)%n]);
				if (t*10 == sum)
				{
					ans = true;
				}
				t -= ary[i];
			}
		}
		puts(ans?"Yes":"No");
	}
	return 0;
}
