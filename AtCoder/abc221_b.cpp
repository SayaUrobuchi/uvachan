#include <iostream>
#include <cstring>
using namespace std;

char s[128], t[128];

int main()
{
	int i, same;
	while (scanf("%s%s", s, t) == 2)
	{
		same = !strcmp(s, t);
		for (i=0; !same&&s[i]&&s[i+1]; i++)
		{
			swap(s[i], s[i+1]);
			same = !strcmp(s, t);
			swap(s[i], s[i+1]);
		}
		puts(same?"Yes":"No");
	}
	return 0;
}

