#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; n>=i*i; n-=i*i, i+=2);
	printf("%d\n", (i>>1));
	return 0;
}
