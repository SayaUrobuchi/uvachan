#include <iostream>
using namespace std;

const int N = 16;

int ary[N];

int main()
{
	int r, d, i;
	scanf("%d%d%d", &r, &d, &ary[0]);
	for (i=1; i<=10; i++)
	{
		ary[i] = r * ary[i-1] - d;
		printf("%d\n", ary[i]);
	}
	return 0;
}
