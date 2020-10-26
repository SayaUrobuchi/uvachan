#include <iostream>

int tbl[128], ary[1048576];
const char *ctbl = " - - - - -   -";
const char *key =  "GFEDCBAgfedcba";
char buf[1024];

int main()
{
	int n, i, j, k, t, d;
	char c;
	for (i=0; i<14; i++)
	{
		tbl[key[i]] = i;
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0, j=0; i<n; i++)
		{
			ary[j] = -1;
			++j;
			scanf("%s", buf);
			t = sscanf(buf, "%c%d", &c, &d);
			if (t == 1)
			{
				d = 1;
			}
			t = tbl[c];
			for (k=0; k<d; k++, j++)
			{
				ary[j] = t;
			}
		}
		for (i=0; i<14; i++)
		{
			printf("%c: ", key[i]);
			for (k=1; k<j; k++)
			{
				if (ary[k] == i)
				{
					putchar('*');
				}
				else
				{
					putchar(ctbl[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}
