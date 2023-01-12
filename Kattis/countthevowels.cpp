#include <iostream>
using namespace std;

const char* vowel = "aeiouAEIOU";

int tbl[128];
char s[128];

int main()
{
	int i, ans;
	for (i=0; vowel[i]; ++i)
	{
		tbl[vowel[i]] = 1;
	}
	scanf("%[^\r\n]", s);
	for (i=0, ans=0; s[i]; ++i)
	{
		ans += tbl[s[i]];
	}
	printf("%d\n", ans);
	return 0;
}