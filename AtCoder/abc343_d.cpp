#include <iostream>
#include <map>
using namespace std;

const int N = 200005;

long long ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int cur = 1;
	map<long long, int> mp;
	mp[0] = n;
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (--mp[ary[a]] == 0)
		{
			--cur;
		}
		if (++mp[ary[a]+=b] == 1)
		{
			++cur;
		}
		printf("%d\n", cur);
	}
	return 0;
}
