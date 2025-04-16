#include <iostream>
using namespace std;

const int SLEN = 16;
const char *KEY = "ACGT";

char buf[SLEN];
bool tbl[128];

int main()
{
	int i, j;
	for (i=0; KEY[i]; i++)
	{
		tbl[KEY[i]] = true;
	}
	scanf("%s", buf);
	int ans = 0;
	for (i=0; buf[i]; i=j)
	{
		if (!tbl[buf[i]])
		{
			j = i + 1;
		}
		else
		{
			for (j=i+1; buf[j]&&tbl[buf[j]]; j++);
			ans = max(ans, j-i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
