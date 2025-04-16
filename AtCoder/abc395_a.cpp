#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	bool inc = true;
	for (i=1; i<n&&inc; i++)
	{
		if (ary[i-1] >= ary[i])
		{
			inc = false;
		}
	}
	puts(inc ? "Yes" : "No");
	return 0;
}
