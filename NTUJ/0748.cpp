#include <stdio.h>
#include <string.h>

char lan1[1005], lan2[1005], nam1[1005], nam2[1005], res1[1005], res2[1005];

int get_lan(char *s)
{
	if(*s == 'c')
	{
		return 0;
	}
	else if(*s == 'e')
	{
		if(*(s+1) == 'n')
		{
			return 1;
		}
		else
		{
			return 8;
		}
	}
	else if(*s == 'f')
	{
		return 2;
	}
	else if(*s == 'd')
	{
		return 3;
	}
	else if(*s == 'h')
	{
		return 4;
	}
	else if(*s == 'i')
	{
		return 5;
	}
	else if(*s == 'j')
	{
		return 6;
	}
	else if(*s == 'p')
	{
		return 7;
	}
	return -1;
}

int get_res(char *s, int lt)
{
	if(lt == 0)
	{
		return *s=='K' ? 0 : (*s=='N' ? 1 : 2);
	}
	else if(lt == 1)
	{
		return *s=='R' ? 0 : (*s=='S' ? 1 : 2);
	}
	else if(lt == 2)
	{
		return *s=='P' ? 0 : (*s=='C' ? 1 : 2);
	}
	else if(lt == 3)
	{
		return *(s+1)=='t' ? 0 : (*s=='S' ? 1 : 2);
	}
	else if(lt == 4)
	{
		return *s=='K' ? 0 : (*s=='O' ? 1 : 2);
	}
	else if(lt == 5)
	{
		return (*s=='S'||*(s+2)=='c') ? 0 : (*s=='F' ? 1 : 2);
	}
	else if(lt == 6)
	{
		return *s=='G' ? 0 : (*s=='C' ? 1 : 2);
	}
	else if(lt == 7)
	{
		return *s=='K' ? 0 : (*s=='N' ? 1 : 2);
	}
	else if(lt == 8)
	{
		return *(s+2)=='e' ? 0 : (*s=='T' ? 1 : 2);
	}
	return -1;
}

int comp(int p, int q)
{
	if(p == (q+2)%3)
	{
		return 1;
	}
	else if(p == q)
	{
		return 0;
	}
	return -1;
}

int main()
{
	int cas, lt1, lt2, sc1, sc2, r1, r2;
	cas = 0;
	while(scanf("%s%s%s%s", lan1, nam1, lan2, nam2) == 4)
	{
		lt1 = get_lan(lan1);
		lt2 = get_lan(lan2);
		sc1 = sc2 = 0;
		while(scanf("%s", res1) == 1)
		{
			if(*res1 == '.' || *res1 == '-')
			{
				break;
			}
			scanf("%s", res2);
			r1 = get_res(res1, lt1);
			r2 = get_res(res2, lt2);
			if(comp(r1, r2) > 0)
			{
				sc1++;
			}
			else if(comp(r1, r2) < 0)
			{
				sc2++;
			}
		}
		printf("Game #%d:\n", ++cas);
		printf("%s: %d point%s\n", nam1, sc1, sc1==1?"":"s");
		printf("%s: %d point%s\n", nam2, sc2, sc2==1?"":"s");
		if(sc1 == sc2)
		{
			printf("TIED GAME\n");
		}
		else
		{
			printf("WINNER: %s\n", sc1>sc2?nam1:nam2);
		}
		printf("\n");
		if(*res1 == '.')
		{
			break;
		}
	}
	return 0;
}
