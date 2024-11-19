#include <iostream>
using namespace std;

const int LIM = 3500;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	long long ansc, ansa, ansb;
	bool got_ans = false;
	for (i=1; i<=LIM&&!got_ans; i++)
	{
		for (j=1; j<=LIM&&!got_ans; j++)
		{
			long long mom = n * 1LL * j * i;
			long long a = 4LL * i * j;
			long long b = 1LL * n * j;
			long long c = 1LL * n * i;
			long long son = a - b - c;
			if (son > 0 && mom % son == 0)
			{
				ansa = i;
				ansb = j;
				ansc = mom / son;
				got_ans = true;
			}
		}
	}
	printf("%lld %lld %lld\n", ansa, ansb, ansc);
	//printf("%.0lf\n", (1.0/ansa + 1.0/ansb + 1.0/ansc) * n);
	return 0;
}