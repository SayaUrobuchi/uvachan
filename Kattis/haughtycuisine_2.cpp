#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

int main()
{
	int n, i;
	char s[32];
	scanf("%*d%d", &n);
	printf("%d\n", n);
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		puts(s);
	}
	return 0;
}
