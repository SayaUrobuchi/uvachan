#include <stdio.h>

int hand[2][52];
int s[2], e[2];
int table[52];
char str[10];

int decode()
{
	if(str[1] == 'A')
	{
		return 4;
	}
	else if(str[1] == 'J')
	{
		return 1;
	}
	else if(str[1] == 'Q')
	{
		return 2;
	}
	else if(str[1] == 'K')
	{
		return 3;
	}
	return 0;
}

int main()
{
	int n, i, turn, need, temp;
	while(scanf("%s", str) == 1)
	{
		if(str[0] == '#')
		{
			break;
		}
		hand[0][25] = decode();
		scanf("%s", str);
		hand[1][25] = decode();
		for(i=24; i>-1; i--)
		{
			scanf("%s", str);
			hand[0][i] = decode();
			scanf("%s", str);
			hand[1][i] = decode();
		}
		for(turn=0, s[0]=s[1]=0, e[0]=e[1]=26, n=0, need=0; ; turn=1-turn)
		{
			if(s[turn] == e[turn])
			{
				printf("%d%3d\n", 1+turn, e[1-turn]-s[1-turn]);
				break;
			}
			if(need)
			{
				for(temp=0; s[turn]!=e[turn]&&need; need--)
				{
					table[n++] = temp = hand[turn][(s[turn]++)%52];
					if(temp)
					{
						break;
					}
				}
				if(!need)
				{
					for(i=0; i<n; i++)
					{
						hand[1-turn][(e[1-turn]++)%52] = table[i];
					}
					n = 0;
				}
				else if(s[turn] == e[turn] && !temp)
				{
					printf("%d%3d\n", 1+turn, e[1-turn]-s[1-turn]);
					break;
				}
				need = temp;
			}
			else
			{
				table[n++] = need = hand[turn][(s[turn]++)%52];
			}
		}
	}
	return 0;
}
