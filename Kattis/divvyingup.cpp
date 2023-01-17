#include <iostream>
using namespace std;

int main()
{
	int n, i, t, sum;
	scanf("%d", &n);
	for (i=0, sum=0; i<n; i++)
	{
		scanf("%d", &t);
		sum += t;
	}
	puts(sum%3?"no":"yes");
	return 0;
}
