#include <iostream>
using namespace std;

const char *KEY = "atcoder";

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%.*s\n", b-a+1, KEY+a-1);
	return 0;
}
