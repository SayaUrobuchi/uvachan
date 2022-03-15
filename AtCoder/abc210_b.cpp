#include <iostream>
using namespace std;

const char *ans[] = {"Takahashi", "Aoki"};

char s[1048576];

int main()
{
	int i;
	while (scanf("%*d%s", s) == 1)
	{
		for (i=0; s[i]=='0'; i++);
		puts(ans[i&1]);
	}
	return 0;
}
