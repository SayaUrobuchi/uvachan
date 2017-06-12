#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char area[32][10];
int dif[32];

int main()
{
	int count, i, h, m, type, tmp;
	char buf[1000], buf2[1000];
	strcpy(area[0], "UTC");
	dif[0] = 0;
	strcpy(area[1], "GMT");
	dif[1] = 0;
	strcpy(area[2], "BST");
	dif[2] = 2;
	strcpy(area[3], "IST");
	dif[3] = 2;
	strcpy(area[4], "WET");
	dif[4] = 0;
	strcpy(area[5], "WEST");
	dif[5] = 2;
	strcpy(area[6], "CET");
	dif[6] = 2;
	strcpy(area[7], "CEST");
	dif[7] = 4;
	strcpy(area[8], "EET");
	dif[8] = 4;
	strcpy(area[9], "EEST");
	dif[9] = 6;
	strcpy(area[10], "MSK");
	dif[10] = 6;
	strcpy(area[11], "MSD");
	dif[11] = 8;
	strcpy(area[12], "AST");
	dif[12] = -8;
	strcpy(area[13], "ADT");
	dif[13] = -6;
	strcpy(area[14], "NST");
	dif[14] = -7;
	strcpy(area[15], "NDT");
	dif[15] = -5;
	strcpy(area[16], "EST");
	dif[16] = -10;
	strcpy(area[17], "EDT");
	dif[17] = -8;
	strcpy(area[18], "CST");
	dif[18] = -12;
	strcpy(area[19], "CDT");
	dif[19] = -10;
	strcpy(area[20], "MST");
	dif[20] = -14;
	strcpy(area[21], "MDT");
	dif[21] = -12;
	strcpy(area[22], "PST");
	dif[22] = -16;
	strcpy(area[23], "PDT");
	dif[23] = -14;
	strcpy(area[24], "HST");
	dif[24] = -20;
	strcpy(area[25], "AKST");
	dif[25] = -18;
	strcpy(area[26], "AKDT");
	dif[26] = -16;
	strcpy(area[27], "AEST");
	dif[27] = 20;
	strcpy(area[28], "AEDT");
	dif[28] = 22;
	strcpy(area[29], "ACST");
	dif[29] = 19;
	strcpy(area[30], "ACDT");
	dif[30] = 21;
	strcpy(area[31], "AWST");
	dif[31] = 16;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", buf);
		if(buf[0] == 'n')
		{
			h = 12;
			m = 0;
			type = 1;
		}
		else if(buf[0] == 'm')
		{
			h = 12;
			m = 0;
			type = 0;
		}
		else
		{
			sscanf(buf, "%d%*c%d", &h, &m);
			scanf("%s", buf);
			if(buf[0] == 'a')
			{
				type = 0;
			}
			else
			{
				type = 1;
			}
		}
		scanf("%s%s", buf, buf2);
		for(i=0; ; i++)
		{
			if(!strcmp(area[i], buf2))
			{
				tmp = dif[i];
				break;
			}
		}
		for(i=0; ; i++)
		{
			if(!strcmp(area[i], buf))
			{
				tmp -= dif[i];
				break;
			}
		}
		if(tmp < 0)
		{
			tmp += 48;
		}
		if(tmp % 2)
		{
			m += 30;
			if(m > 59)
			{
				m %= 60;
				h++;
				if(h == 12)
				{
					type++;
					type %= 2;
				}
			}
		}
		tmp /= 2;
		if(tmp > 11)
		{
			tmp -= 12;
			type++;
			type %= 2;
		}
		if(h < 12)
		{
			h += tmp;
			if(h > 11)
			{
				type++;
				type %= 2;
				if(h > 12)
				{
					h -= 12;
				}
			}
		}
		else
		{
			h += tmp;
			if(h > 23)
			{
				type++;
				type %= 2;
				h -= 12;
			}
			else if(h > 12)
			{
				h -= 12;
			}
		}
		if(type)
		{
			if(h == 12 && !m)
			{
				printf("noon\n");
			}
			else
			{
				printf("%d:%02d p.m.\n", h, m);
			}
		}
		else
		{
            if(h == 12 && !m)
			{
				printf("midnight\n");
			}
			else
			{
				printf("%d:%02d a.m.\n", h, m);
			}
		}
	}
	return 0;
}
