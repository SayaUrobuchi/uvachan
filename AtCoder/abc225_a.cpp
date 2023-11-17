#include <iostream>
#include <algorithm>
using namespace std;

int tbl[] = {1, 1, 2, 6};
char s[4];

int main()
{
	int i, j, ans;
	scanf("%s", s);
	sort(s, s+3);
	for (i=0, ans=6; i<3; i=j)
	{
		for (j=i+1; j<3&&s[i]==s[j]; j++);
		ans /= tbl[j-i];
	}
	printf("%d\n", ans);
	return 0;
}
