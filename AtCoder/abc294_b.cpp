#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		string res;
		for (j=0; j<m; j++)
		{
			int t;
			scanf("%d", &t);
			res += t ? 'A' + t - 1 : '.';
		}
		puts(res.c_str());
	}
	return 0;
}
