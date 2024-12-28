#include <iostream>
using namespace std;

inline int dd(int t)
{
	int res = 0;
	while (t)
	{
		res += t%10;
		t /= 10;
	}
	return res;
}

int main()
{
	int a, b, c, d, i, j, k;
	long long isum, jsum, ksum, ans;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		for (i=a, isum=0, j=a-1, jsum=0, k=a-1, ksum=0, ans=0; i<=b; i++)
		{
			for (; j<=b&&jsum-isum<c; jsum+=dd(++j));
			for (; k<=b&&ksum-isum<=d; ksum+=dd(++k));
			ans += k-j;
			//printf(".. %d (%d)=> %d %d (%d, %d)\n", i, isum, j, k, jsum, ksum);
			isum += dd(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

