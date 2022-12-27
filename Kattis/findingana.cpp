#include <iostream>
using namespace std;

char s[1024];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]!='a'; i++);
	puts(s+i);
	return 0;
}