#include <iostream>
using namespace std;

const int N = 128;

int ary[N];
bool appear[1024];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	bool found = false;
	for (i=0; i<n&&!found; i++)
	{
		for (j=i+1; j<n&&!found; j++)
		{
			int t = ary[i] + ary[j];
			if (t < 1000 && appear[1000-t])
			{
				found = true;
			}
		}
		appear[ary[i]] = true;
	}
	puts(found ? "Yes" : "No");
	return 0;
}
