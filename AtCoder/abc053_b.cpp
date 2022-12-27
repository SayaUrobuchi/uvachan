#include <iostream>
using namespace std;

char s[200005];

int main()
{
	int i, st, ed;
	scanf("%s", s);
	for (i=0, st=2000005, ed=0; s[i]; i++)
	{
		if (s[i] == 'A')
		{
			st = min(st, i);
		}
		else if (s[i] == 'Z')
		{
			ed = max(ed, i);
		}
	}
	printf("%d\n", ed-st+1);
	return 0;
}