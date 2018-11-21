#include <stdio.h>
#include <string.h>

int ln[100005], lm[100005], llen[100005], lloc[100005], *lnext[100005], pool[100005];
char pat[100005], tex[100005];

int chk(int n, int m, int k)
{
	return (k-m)%2==0 && k>=m && (k==0 || n+m>0);
}

int main()
{
	int cas1, cas2, i, j, k, lnum, len, pp, las, ppt;
	cas1 = 1;
	while(gets(pat))
	{
		lnum = 0;
		if(*pat != '*' && *pat != '#')
		{
			ln[0] = 0;
			lm[0] = 0;
			lnum++;
		}
		ppt = 0;
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
				lloc[lnum] = i;
				lnext[lnum] = pool+ppt;
				lnext[lnum][0] = -1;
				for(k=0, j=-1; pat[i]; i++, k++)
				{
					if(pat[i] >= 48 && pat[i] <= 57)
					{
						llen[lnum]++;
						while(j!=-1 && pat[i]!=pat[lloc[lnum]+j])
						{
							j = lnext[lnum][j];
						}
						lnext[lnum][k+1] = ++j;
					}
					else
					{
						break;
					}
				}
				ppt += llen[lnum] + 1;
			}
		}
		cas2 = 1;
		while(gets(tex))
		{
			if(strcmp(tex, "END") == 0 || strcmp(tex, "QUIT") == 0)
			{
				break;
			}
			len = strlen(tex);
			for(i=0, pp=-1, las=-1; i+1<lnum; )
			{
				for(pp++, j=0; pp<len; pp++)
				{
					while(j == llen[i+1] || (j!=-1 && tex[pp]!=pat[j+lloc[i+1]]))
					{
						j = lnext[i+1][j];
					}
					j++;
					if(j == llen[i+1])
					{
						if((i+2<lnum || pp==len-1) && chk(ln[i], lm[i], pp-las-llen[i+1]))
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
		if(strcmp(tex, "QUIT") == 0)
		{
			break;
		}
		cas1++;
	}
	return 0;
}
