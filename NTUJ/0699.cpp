#include <stdio.h>

int ln[100005], lm[100005], llen[100005];
long long tim[100005], has[100005], lhas[100005];
char pat[100005], tex[100005];

int chk(int n, int m, int k)
{
	return (k-m)%2==0 && k>=m && (k==0 || n+m>0);
}

int main()
{
	int cas1, cas2, i, lnum, len, pp, las;
	long long bas;
	bas = 13;
	tim[0] = 1;
	for(i=1; i<=100000; i++)
	{
		tim[i] = tim[i-1] * bas;
	}
	cas1 = 1;
	while(scanf("%s", pat) == 1)
	{
		lnum = 0;
		if(*pat != '*' && *pat != '#')
		{
			ln[0] = 0;
			lm[0] = 0;
			lnum++;
		}
		for(i=0; pat[i]; lnum++)
		{
			if(pat[i] == '*' || pat[i] == '#')
			{
				ln[lnum] = 0;
				lm[lnum] = 0;
				for(; pat[i]; i++)
				{
					if(pat[i] == '*')
					{
						ln[lnum]++;
					}
					else if(pat[i] == '#')
					{
						lm[lnum]++;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				llen[lnum] = 0;
				lhas[lnum] = 0;
				for(; pat[i]; i++)
				{
					if(pat[i] >= 48 && pat[i] <= 57)
					{
						llen[lnum]++;
						lhas[lnum] = lhas[lnum]*bas+pat[i]-48;
					}
					else
					{
						break;
					}
				}
			}
		}
		cas2 = 1;
		while(scanf("%s", tex) == 1)
		{
			if(*tex == 'E' || *tex == 'Q')
			{
				break;
			}
			has[0] = *tex - 48;
			for(i=1; tex[i]; i++)
			{
				has[i] = has[i-1] * bas + tex[i] - 48;
			}
			len = i;
			for(i=0, pp=-1, las=-1; i+1<lnum; )
			{
				pp += llen[i+1];
				for(; pp<len; pp++)
				{
					if(has[pp]-(pp>=llen[i+1]?has[pp-llen[i+1]]:0)*tim[llen[i+1]] == lhas[i+1])
					{
						/*printf("XDDD %d %d %d\n", ln[i], lm[i], pp-las-llen[i+1]);*/
						if(chk(ln[i], lm[i], pp-las-llen[i+1]))
						{
							break;
						}
					}
				}
				if(pp >= len)
				{
					break;
				}
				las = pp;
				i += 2;
			}
			if(i+1 < lnum)
			{
				printf("%d.%d. not\n", cas1, cas2);
			}
			else
			{
				if(i < lnum)
				{
					if(chk(ln[i], lm[i], len-1-pp))
					{
						printf("%d.%d. match\n", cas1, cas2);
					}
					else
					{
						printf("%d.%d. not\n", cas1, cas2);
					}
				}
				else
				{
					if(pp == len-1)
					{
						printf("%d.%d. match\n", cas1, cas2);
					}
					else
					{
						printf("%d.%d. not\n", cas1, cas2);
					}
				}
			}
			cas2++;
		}
		if(*tex == 'Q')
		{
			break;
		}
		cas1++;
	}
	return 0;
}
