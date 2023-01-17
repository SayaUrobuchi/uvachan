#include <iostream>
using namespace std;

char s[105];

int main()
{
	int i, sum;
	fgets(s, sizeof(s), stdin);
	for (i=0, sum=0; s[i]>=' '; i++)
	{
		sum += s[i];
	}
	printf("%c\n", sum/i);
	return 0;
}
