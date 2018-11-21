#include <stdio.h>

class FoxIntegerLevelThree
{
public:
	long long count(long long p, long long q)
	{
		long long res, st, ed;
		p--;
		res = 0;
		st = ((p-1)/9)*9+1;
		ed = ((q-1)/9)*9+1;
		res += (ed)/9-(st)/9;
		printf("%lld\n", res);
		st = ((p-4)/9)*9+4;
		ed = ((q-4)/9)*9+4;
		res += ((ed+5)/9+1)/2-((st+5)/9+1)/2;
		printf("%lld\n", res);
		res += (ed/9+9)/14-(st/9+9)/14;
		printf("%lld\n", res);
		st = ((p)/9);
		ed = ((q)/9);
		res += ed/9-st/9;
		printf("%lld\n", res);
		res += (ed+2)/9-(st+2)/9;
		printf("%lld\n", res);
		st = ((p-7)/9)*9+7;
		ed = ((q-7)/9)*9+7;
		res += (ed/9+3)/4-(st/9+3)/4;
		printf("%lld\n", res);
		res += (ed/9+3)/5-(st/9+3)/5;
		printf("%lld\n", res);
		res -= (ed/9+3)/20-(st/9+3)/20;
		printf("%lld\n", res);
		return res;
	}
};
