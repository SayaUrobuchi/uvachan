#include <iostream>
using namespace std;

char s0[16], s1[16];

int main()
{
	int i;
	while (scanf("%s%s", s0, s1) == 2)
	{
		for (i=0; s0[i]&&s1[i]&&s0[i]==s1[i]; i++);
		puts(s0[i]<s1[i]?"Yes":"No");
	}
	return 0;
}

