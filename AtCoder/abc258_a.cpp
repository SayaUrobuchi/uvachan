#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 21*60 + n;
	int h = ans / 60;
	int m = ans % 60;
	printf("%02d:%02d\n", h, m);
	return 0;
}
