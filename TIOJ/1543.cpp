#include <stdio.h>
#include <string.h>

int stkx[1000001], stky[1000001];
char str[100001], cmd[100001];

int main()
{
	int qq, top, p, q, r, l, c, tt;
	qq = 0;
	top = -1;
	while(gets(str))
	{
		if(strcmp(str, "Start Stacking!!") == 0)
		{
			while(gets(str))
			{
				if(strcmp(str, "End Stacking.") == 0)
				{
					break;
				}
				else if(*str)
				{
					if(*str == 'S')
					{
						sscanf(str+11, "%d,%d", &p, &q);
						for(l=0, r=top, tt=-1; l<=r; )
						{
							c = ((l+r)>>1);
							if(p <= stkx[c] && q <= stky[c])
							{
								tt = c;
								l = c+1;
							}
							else
							{
								r = c-1;
							}
						}
						top = tt + 1;
						stkx[top] = p;
						stky[top] = q;
					}
					else
					{
						if(top+1 == 0)
						{
							printf("Query %d: None.\n", ++qq);
						}
						else if(top+1 == 1)
						{
							printf("Query %d: %d box.\n", ++qq, top+1);
						}
						else
						{
							printf("Query %d: %d boxes.\n", ++qq, top+1);
						}
					}
				}
			}
			break;
		}
	}
	return 0;
}
