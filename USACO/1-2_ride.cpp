/*
ID: sa072682
LANG: C
TASK: ride
*/

#include <stdio.h>

int main()
{
	int i, s1, s2;
	char str1[20], str2[20];
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	scanf("%s%s", str1, str2);
	for(i=0, s1=1; str1[i]; i++)
	{
		s1 *= str1[i] - 64;
		s1 %= 47;
	}
	for(i=0, s2=1; str2[i]; i++)
	{
		s2 *= str2[i] - 64;
		s2 %= 47;
	}
	if(s1 == s2) puts("GO");
	else puts("STAY");
	return 0;
}
