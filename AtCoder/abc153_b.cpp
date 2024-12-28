#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		m -= t;
	}
	puts(m<=0 ? "Yes" : "No");
	return 0;
}
