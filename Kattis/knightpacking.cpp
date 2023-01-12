#include <iostream>
using namespace std;

const char* ans[] = {"second", "first"};

int main()
{
	int n;
	scanf("%d", &n);
	printf("%s\n", ans[n&1]);
	return 0;
}