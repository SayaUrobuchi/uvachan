#include <iostream>
#include <algorithm>
using namespace std;

const int N = 7;

int ary[N];

int main()
{
	int i;
	for (i=0; i<N; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+N);
	printf("%d %d %d\n", ary[0], ary[1], ary[N-1]-ary[0]-ary[1]);
	return 0;
}
