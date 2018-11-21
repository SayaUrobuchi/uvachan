#include <stdio.h>
#include <string.h>

char cmd[1000][4];
int reg[10];

int main()
{
	int count, n, i, type, x, y, ans;
	char buf[4];
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		memset(cmd, 0, sizeof(cmd));
		memset(reg, 0, sizeof(reg));
		n = 0;
		while(gets(cmd[n]) && cmd[n][0])
		{
			cmd[n][0] -= 48;
			cmd[n][1] -= 48;
			cmd[n++][2] -= 48;
		}
		ans = 1;
		for(i=0; ; i++)
		{
			type = cmd[i][0];
			x = cmd[i][1];
			y = cmd[i][2];
			if(type == 1)
			{
				break;
			}
			else if(type == 2)
			{
				reg[x] = y;
			}
			else if(type == 3)
			{
				reg[x] += y;
				reg[x] %= 1000;
			}
			else if(type == 4)
			{
				reg[x] *= y;
				reg[x] %= 1000;
			}
			else if(type == 5)
			{
				reg[x] = reg[y];
			}
			else if(type == 6)
			{
				reg[x] += reg[y];
				reg[x] %= 1000;
			}
			else if(type == 7)
			{
				reg[x] *= reg[y];
				reg[x] %= 1000;
			}
			else if(type == 8)
			{
				reg[x] = cmd[reg[y]][0] * 100 + cmd[reg[y]][1] * 10 + cmd[reg[y]][2];
			}
			else if(type == 9)
			{
				cmd[reg[y]][0] = reg[x] / 100;
				cmd[reg[y]][1] = (reg[x] / 10) % 10;
				cmd[reg[y]][2] = reg[x] % 10;
			}
			else
			{
				if(reg[y])
				{
					i = reg[x] - 1;
				}
			}
			ans++;
		}
		printf("%d\n", ans);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
