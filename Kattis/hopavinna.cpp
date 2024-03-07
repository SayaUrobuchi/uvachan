#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int a = 0;
	int b;
	scanf("%d", &b);
	for (i=1; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		t += min(a, b);
		a = b;
		b = t;
	}
	printf("%d\n", min(a, b));
	return 0;
}