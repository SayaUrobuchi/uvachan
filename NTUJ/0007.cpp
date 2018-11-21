#include <stdio.h>

int tbl[20], hash[128];
char s1[5], s2[5], s3[5];

int trans(char* s)
{
	return hash[*s];
}

int getsc(int type)
{
	if(type == 1)
	{
		return 11;
	}
	else if(type > 10)
	{
		return 10;
	}
	return type;
}

int main()
{
	int n, i, c1, c2, c3, temp, dsc, psc, lose, win;
	hash['A'] = 1;
	hash['T'] = 10;
	hash['J'] = 11;
	hash['Q'] = 12;
	hash['K'] = 13;
	for(i='2'; i<='9'; i++)
	{
		hash[i] = i - 48;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1; i<=13; i++)
		{
			tbl[i] = 4 * n;
		}
		scanf("%s%s%s", s1, s2, s3);
		tbl[c1=trans(s1)]--;
		tbl[c2=trans(s2)]--;
		tbl[c3=trans(s3)]--;
		dsc = getsc(c1);
		psc = getsc(c2)+getsc(c3);
		if(psc > 21)
		{
			psc -= 10;
		}
		for(i=1, lose=0, win=0; i<=13; i++)
		{
			temp = dsc + getsc(i);
			if(temp > 21)
			{
				temp -= 10;
			}
			if(temp >= psc)
			{
				lose += tbl[i];
			}
			else
			{
				win += tbl[i];
			}
		}
		printf("%.3lf%%\n", win*100.0/(win+lose));
	}
	return 0;
}
