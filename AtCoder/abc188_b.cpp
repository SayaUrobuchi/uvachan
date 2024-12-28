#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	long long sum = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t * ary[i];
	}
	puts(sum ? "No" : "Yes");
	return 0;
}
