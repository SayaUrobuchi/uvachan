#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int ary[N], pos[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	vector<int> v;
	for (i=1, j=1; !pos[j]; i++, j=ary[j])
	{
		pos[j] = i;
		v.emplace_back(j);
	}
	printf("%llu\n", v.size()-pos[j]+1);
	printf("%d", v[pos[j]-1]);
	for (i=pos[j]; i<v.size(); i++)
	{
		printf(" %d", v[i]);
	}
	puts("");
	return 0;
}
