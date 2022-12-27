#include <iostream>
using namespace std;

long long ary[512], tbl[512];

int main()
{
	int count, m, i;
	long long n, j, a, b;
	ary[1] = 9;
	tbl[1] = 1;
	for (i=2, j=90; ary[i-1]<1e18; i++, j*=10)
	{
		ary[i] = ary[i-1] + i*j;
		tbl[i] = tbl[i-1] * 10;
	}
	m = i;
	cin >> count;
	while (count--)
	{
		cin >> n;
		i = lower_bound(ary, ary+m, n) - ary;
		n -= ary[i-1];
		a = (n-1) / i + tbl[i];
		b = i - ((n-1) % i + 1);
		while (b--)
		{
			a /= 10;
		}
		cout << a%10 << "\n";
	}
	return 0;
}

