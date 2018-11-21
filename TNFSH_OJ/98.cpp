#include <stdio.h>

int main()
{
	/* 
	1 Light-second(LS) is 299792458 metres.
	1 Light-minute(LM) is XXXXXXXXX metres.
	1 Light-hour(LH) is XXXXXXXXX metres.
	1 Light-day(LD) is XXXXXXXXX metres.
	1 Light-week(LW) is XXXXXXXXX metres.
	1 Light-year(LY) is XXXXXXXXX metres.
	*/
	long long ls = 299792458;
	printf("1 Light-second(LS) is %lld metres.\n", ls);
	printf("1 Light-minute(LM) is %lld metres.\n", ls*=60);
	printf("1 Light-hour(LH) is %lld metres.\n", ls*=60);
	printf("1 Light-day(LD) is %lld metres.\n", ls*=24);
	printf("1 Light-week(LW) is %lld metres.\n", ls*7);
	printf("1 Light-year(LY) is %lld metres.\n", ls*365);
	return 0;
}
