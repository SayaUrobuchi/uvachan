#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int con = 0;
	int mx = 0;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b)
		{
			++con;
			mx = max(mx, con);
		}
		else
		{
			con = 0;
		}
	}
	puts(mx >= 3 ? "Yes" : "No");
	return 0;
}
