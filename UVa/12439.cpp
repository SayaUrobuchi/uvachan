#include <stdio.h>
#include <string.h>

const char *tbl[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int get_m(char *s)
{
	int i;
	for(i=0; i<12; i++)
	{
		if(strcmp(s, tbl[i]) == 0)
		{
			return i+1;
		}
	}
}

int main()
{
	int cas, count, d, m, ans;
	long long d0, d1, d2, y, sy;
	char ms[128];
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d, %lld", ms, &d, &y);
		m = get_m(ms);
		sy = y-(y&3);
		d0 = d+m*100+y*10000;
		scanf("%s%d, %lld", ms, &d, &y);
		m = get_m(ms);
		d1 = d+m*100+y*10000;
		d2 = sy*10000+229;
		y = sy;
		ans = 0;
		if(d2 < d0)
		{
			d2 += 40000;
			y += 4;
		}
		for(; d2<=d1; d2+=40000, y+=4)
		{
			if(y%400 == 0)
			{
				break;	
			}		
			if(y%400 && y%100==0)
			{
				continue;
			}
			ans++;
		}
		if(d2 <= d1)
		{
			ans += 97*(sy=d1/4000000-y/400);
			d2 += sy*4000000;
			y += sy*400;
			for(; d2<=d1; d2+=40000, y+=4)
			{
				if(y%400 && y%100==0)
				{
					continue;
				}
				ans++;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
