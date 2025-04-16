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
	bool found = false;
	for (i=0; i+2<n&&!found; i++)
	{
		if (ary[i] == ary[i+1] && ary[i] == ary[i+2])
		{
			found = true;
		}
	}
	puts(found ? "Yes" : "No");
	return 0;
}
