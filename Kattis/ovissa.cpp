#include <iostream>
using namespace std;

char s[100005];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++);
	printf("%d\n", i);
	return 0;
}
