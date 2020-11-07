#include <iostream>

//                 012345678901234567890123456789
const char *key = "0123456789ACDEFHJKLMNPRTVWX";

int tbl[128];
int eff[] = {2, 4, 5, 7, 8, 10, 11, 13};
char s[1048576];

int main()
{
	int count, cas, i;
	long long ans, sum;
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = i;
	}
	tbl['B'] = 8;
	tbl['G'] = 11;
	tbl['I'] = 1;
	tbl['O'] = 0;
	tbl['Q'] = 0;
	tbl['S'] = 5;
	tbl['U'] = 24;
	tbl['Y'] = 24;
	tbl['Z'] = 2;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &cas, s);
		for (i=0, ans=0, sum=0; i<8; i++)
		{
			sum += tbl[s[i]] * eff[i];
			ans = ans*27 + tbl[s[i]];
		}
		if (sum%27 == tbl[s[8]])
		{
			printf("%d %lld\n", cas, ans);
		}
		else
		{
			printf("%d Invalid\n", cas);
		}
	}
	return 0;
}
