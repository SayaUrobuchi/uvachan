#include <stdio.h>
#include <string.h>

unsigned long long ten[20], tbl[20];
char space[1001], dash[1001];
char buf[1005], buf2[1005];

int main()
{
	int i, l, dlen, slen, lines, remain;
	unsigned long long a, b, res;
	ten[0] = 1;
	for(i=1; i<18; i++)
	{
		ten[i] = ten[i-1] * 10;
	}
	memset(space, ' ', sizeof(space));
	space[1000] = 0;
	memset(dash, '-', sizeof(dash));
	dash[1000] = 0;
	while(scanf("%llu%llu", &a, &b) == 2)
	{
		sprintf(buf, "%llu", b);
		if(a <= b)
		{
			dlen = strlen(buf);
		}
		else
		{
			sprintf(buf2, "%llu", a);
			dlen = strlen(buf2);
		}
		/*printf("DLEN %d\n", dlen);*/
		for(l=strlen(buf), i=0, lines=0, res=0, remain=0; i<l; i++)
		{
			tbl[i] = (buf[l-i-1] - '0') * a;
			/*printf("%d %I64d\n", i, tbl[i]);*/
			if(tbl[i])
			{
				lines++;
				if(i)
				{
					res += tbl[i] * ten[i-1];
				}
				else
				{
					remain = tbl[0] % 10;
					res += tbl[0] / 10;
				}
			}
		}
		slen = 1;
		if(res)
		{
			sprintf(buf, "%llu", res);
			slen += strlen(buf);
		}
		if(slen < dlen)
		{
			slen = dlen;
		}
		/*printf("%d %d\n", slen, dlen);*/
		printf("%*llu\n%*llu\n", slen, a, slen, b);
		printf("%.*s%.*s\n", slen-dlen, space, dlen, dash);
		if(lines >= 2)
		{
			for(i=0; i<l; i++)
			{
				if(tbl[i])
				{
					printf("%*llu\n", slen-i, tbl[i]);
				}
			}
			printf("%.*s\n", slen, dash);
		}
		if(res)
		{
			printf("%s%d\n\n", buf, remain);
		}
		else
		{
			printf("%*d\n\n", slen, remain);
		}
	}
	return 0;
}
