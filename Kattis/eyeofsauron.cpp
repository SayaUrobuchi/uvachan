#include <iostream>
using namespace std;

char s[128];

int main()
{
	int i, j;
	scanf("%s", s);
	for (i=0; s[i]!='('; ++i);
	for (j=0; s[i+j+2]; ++j);
	puts(i==j?"correct":"fix");
	return 0;
}