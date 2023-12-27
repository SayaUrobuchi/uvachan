#include <iostream>
using namespace std;

int main()
{
	int n;
	char buf[1024];
	scanf("%s%d", buf, &n);
	while (n--)
	{
		printf("%s", buf);
	}
	puts("");
	return 0;
}
