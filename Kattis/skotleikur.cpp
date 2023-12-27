#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

int main()
{
	int a, b, c, i;
	vector<pp> v;
	scanf("%d%d%d", &c, &a, &b);
	for (i=0; i<=c; i+=a)
	{
		if ((c - i) % b == 0)
		{
			v.emplace_back(i/a, (c-i)/b);
		}
	}
	printf("%llu\n", v.size());
	for (i=0; i<v.size(); i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}
