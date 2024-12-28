#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	bool appear = false;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == m)
		{
			appear = true;
		}
	}
	puts(appear ? "Yes" : "No");
	return 0;
}
