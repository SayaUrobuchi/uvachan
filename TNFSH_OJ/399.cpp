#include <stdio.h>
#include <string.h>

int tbl[16];
char s0[10005], s1[10005];

int get_num(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c-'A')+10;
	}
	return c-'0';
}

int main()
{
	int i, l0, l1, ll, zz, a, b, c;
	for (i=0; i<10; i++)
	{
		tbl[i] = '0'+i;
	}
	for (i=10; i<16; i++)
	{
		tbl[i] = 'A'+(i-10);
	}
	while (fgets(s0, 10004, stdin))
	{
		s0[strlen(s0)-1] = 0;
		fgets(s1, 10004, stdin);
		s1[strlen(s1)-1] = 0;
		l0 = strlen(s0);
		l1 = strlen(s1);
		ll = (l0 > l1 ? l0 : l1);
		zz = 0;
		for (i=0; i<ll; i++)
		{
			a = (l0-ll+i>=0 ? get_num(s0[l0-ll+i]) : 0);
			b = (l1-ll+i>=0 ? get_num(s1[l1-ll+i]) : 0);
			c = tbl[a^b];
			if (c == '0' && !zz)
			{
				continue;
			}
			zz = 1;
			printf("%c", tbl[a^b]);
		}
		if (!zz)
		{
			printf("0");
		}
		puts("");
	}
	return 0;
}
