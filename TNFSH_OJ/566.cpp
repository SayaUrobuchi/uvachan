#include<iostream>
using namespace std;

int ary[1048576];

int main() {
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=n-1, j=n; i>=0; i--)
		{
			if (ary[i] == j)
			{
				j--;
			}
		}
		printf("%d\n", j);
	}
	return 0;
}

