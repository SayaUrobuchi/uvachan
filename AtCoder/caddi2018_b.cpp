#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int res = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		res += (t & 1);
	}
	puts(res ? "first" : "second");
	return 0;
}
