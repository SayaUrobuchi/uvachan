#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	long long sum = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
	}
	int t = sum / n;
	int u = sum % n;
	sort(ary, ary+n);
	long long ans = 0;
	for (i=0; i<n; i++)
	{
		int tar = t;
		if (i >= n - u)
		{
			++tar;
		}
		ans += abs(ary[i] - tar);
	}
	printf("%lld\n", ans>>1);
	return 0;
}
