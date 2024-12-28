#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	bool same = true;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i] != ary[0])
		{
			same = false;
		}
	}
	puts(same ? "Yes" : "No");
	return 0;
}
