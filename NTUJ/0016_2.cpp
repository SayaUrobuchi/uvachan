#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int three[60], *sc, p1sc, p2sc, hash[128];
char buf[1000], bb[2000], s[2000], p1h[2000], p2h[2000], hole[2000];
char suit[50]="SDHC";
char val[140]="23456789TJQKA";

int pkcomp(const void *p, const void *q)
{
	return hash[*(char*)p] - hash[*(char*)q];
}

void getpk(int now)
{
	sprintf(buf, "%c%c", val[now%13], suit[now/13]);
}

int issasu()
{
	return bb[1] == bb[3] && bb[1] == bb[5] && bb[1] == bb[7] && bb[1] == bb[9];
}

int getvaln()
{
	int i, j, res;
	for(i=0, res=0; i<10; i=j, res++)
	{
		for(j=i+2; j<10&&bb[i]==bb[j]; j+=2);
	}
	return res;
}

int getord()
{
	if(bb[0] == '2' && bb[2] == '3' && bb[4] == '4' && bb[6] == '5' && bb[8] == 'A')
	{
		return 1;
	}
	return hash[bb[8]] - hash[bb[0]] == 4;
}

int calc()
{
	int i, j, k, sasu, valn, ord, fres;
	strcpy(bb, s);
	qsort(bb, 5, sizeof(char)*2, pkcomp);
	sasu = issasu();
	valn = getvaln();
	ord = (valn==5) ? getord() : 0;
	if(sasu && ord)
	{
		fres = 15 * three[5] + hash[bb[8]] * three[4];
		if(bb[0] == '2' && bb[8] == 'A')
		{
			fres -= hash[bb[8]] * three[4];
		}
	}
	else if(valn == 2 && (bb[0] != bb[2] || bb[6] != bb[8]))
	{
		fres = 14 * three[5] + hash[bb[4]] * three[4];
		if(bb[0] != bb[2])
		{
			fres += hash[bb[0]] * three[3];
		}
		else if(bb[6] != bb[8])
		{
			fres += hash[bb[8]] * three[3];
		}
	}
	else if(valn == 2)
	{
		fres = 13 * three[5] + hash[bb[4]] * three[4];
		if(bb[4] == bb[2])
		{
			fres += hash[bb[6]] * three[3];
		}
		else if(bb[4] == bb[6])
		{
			fres += hash[bb[2]] * three[3];
		}
	}
	else if(sasu)
	{
		fres = 12 * three[5];
		for(i=8; i>=0; i-=2)
		{
			fres += hash[bb[i]] * three[i>>1];
		}
	}
	else if(ord)
	{
		fres = 11 * three[5] + hash[bb[8]] * three[4];
		if(bb[0] == '2' && bb[8] == 'A')
		{
			fres -= hash[bb[8]] * three[4];
		}
	}
	else if(valn == 3)
	{
		for(i=4; i<=8; i+=2)
		{
			if(bb[i] == bb[i-2] && bb[i] == bb[i-4])
			{
				break;
			}
		}
		if(i <= 8)
		{
			fres = 10 * three[5] + hash[bb[i]] * three[4];
			for(j=8, k=3; j>=0; j-=2)
			{
				if(bb[j] != bb[i])
				{
					fres += hash[bb[j]] * three[k--];
				}
			}
		}
		else
		{
			fres = 9 * three[5];
			if(bb[8] == bb[6])
			{
				fres += hash[bb[8]] * three[4];
				if(bb[4] == bb[2])
				{
					fres += hash[bb[4]] * three[3] + hash[bb[0]] * three[2];
				}
				else
				{
					fres += hash[bb[0]] * three[3] + hash[bb[4]] * three[2];
				}
			}
			else
			{
				fres += hash[bb[4]] * three[4] + hash[bb[0]] * three[3] + hash[bb[8]] * three[2];
			}
		}
	}
	else if(valn == 4)
	{
		fres = three[5];
		for(i=2; i<=8; i+=2)
		{
			if(bb[i] == bb[i-2])
			{
				break;
			}
		}
		fres += hash[bb[i]] * three[4];
		for(j=8, k=3; j>=0; j-=2)
		{
			if(bb[j] != bb[i])
			{
				fres += hash[bb[j]] * three[k--];
			}
		}
	}
	else
	{
		fres = 0;
		for(i=8; i>=0; i-=2)
		{
			fres += hash[bb[i]] * three[i>>1];
		}
	}
	return fres;
}

void dfs(char *ptr, char *res)
{
	int temp;
	if(res - s == 10)
	{
		temp = calc();
		if(temp > *sc)
		{
			*sc = temp;
		}
		return;
	}
	for(; *ptr; ptr+=2)
	{
		sprintf(res, "%.2s", ptr);
		dfs(ptr+2, res+2);
	}
}

int main()
{
	int count, cas, i, j, c;
	for(i=0; i<13; i++)
	{
		hash[val[i]] = i;
	}
	three[0] = 1;
	for(i=1; i<6; i++)
	{
		three[i] = three[i-1] * 13;
	}
	cas = 0;
	if(0)
	{
		while(scanf("%s%s", p1h, p2h) == 2)
		{
			strcpy(s, p1h);
			p1sc = calc();
			strcpy(s, p2h);
			p2sc = calc();
			printf("%d : %d, %s\n", p1sc, p2sc, p1sc>=p2sc?"win or tie!":"lose!");
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s%s", p1h, p2h, hole);
		strcat(p1h, hole);
		strcat(p2h, hole);
		printf("%d:", ++cas);
		for(j=0; j<2; j++)
		{
			for(i=0, c=0; i<52; i++)
			{
				getpk(i);
				p1h[12] = 0;
				p2h[12] = 0;
				if(strstr(p1h, buf) != NULL || strstr(p2h, buf) != NULL)
				{
					continue;
				}
				p1sc = -1;
				sc = &p1sc;
				strcpy(p1h+12, buf);
				dfs(p1h, s);
				p2sc = -1;
				sc = &p2sc;
				strcpy(p2h+12, buf);
				dfs(p2h, s);
				if(j ? (p1sc == p2sc) : (p1sc > p2sc))
				{
					if(1)
					{
						if(c && c % 15 == 0)
						{
							printf("\n  ");
						}
						printf(" %s", buf);
					}
					else
					{
						if(c && c % 15 == 0)
						{
							printf("\n%s", buf);
						}
						else
						{
							printf(" %s", buf);
						}
					}
					c++;
				}
			}
			if(c)
			{
				break;
			}
		}
		if(c == 0)
		{
			printf(" LOSER");
		}
		printf("\n");
	}
	return 0;
}
