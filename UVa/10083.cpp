#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE 10

long long mother[300], son[300], buf[300];
char res[2000];

int comp(long long *p, int pl, long long *q, int ql)
{
	int i;
	if(pl != ql)
	{
		return pl - ql;
	}
	for(i=pl-1; i>=0; i--)
	{
		if(p[i] != q[i])
		{
			return p[i]-q[i];
		}
	}
	return 0;
}

int main()
{
	int t, a, b, i, j, k, ml, sl, bl, temp;
	while(scanf("%d%d%d", &t, &a, &b) == 3)
	{
		if(t == 1 || a % b || log10(t)*a - log10(t)*b > 102.0)
		{
			printf("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits.\n", t, a, t, b);
		}
		else if(a == b)
		{
			printf("(%d^%d-1)/(%d^%d-1) 1\n", t, a, t, b);
		}
		else
		{
			memset(mother, 0, sizeof(mother));
			memset(son, 0, sizeof(son));
			for(ml=0, temp=t; temp; mother[ml++]=temp%10, temp/=10);
			for(i=1; i<b; i++)
			{
				for(j=0; j<ml; j++)
				{
					mother[j] *= t;
				}
				for(j=0; j<ml||mother[j]; j++)
				{
					if(mother[j] >= BASE)
					{
						mother[j+1] += mother[j] / BASE;
						mother[j] %= BASE;
					}
				}
				ml = j;
			}
			memcpy(son, mother, sizeof(mother));
			sl = ml;
			for(i=1, temp=a/b; i<temp; i++)
			{
				memset(buf, 0, sizeof(buf));
				for(j=0; j<ml; j++)
				{
					for(k=0; k<sl; k++)
					{
						buf[j+k] += mother[j] * son[k];
					}
				}
				for(j=0; j<ml+sl||buf[j]; j++)
				{
					if(buf[j] >= BASE)
					{
						buf[j+1] += buf[j] / BASE;
						buf[j] %= BASE;
					}
				}
				memcpy(son, buf, sizeof(buf));
				sl = j - (buf[j-1] == 0);
				/*for(j=sl-1; j>=0; j--)
				{
					printf("%d", son[j]);
				}
				printf("\n");*/
			}
			/*for(i=sl-1; i>=0; i--)
			{
				printf("%d", son[i]);
			}
			printf("\n");*/
			mother[0]--;
			for(j=0; j<ml; j++)
			{
				if(mother[j] < 0)
				{
					mother[j] += BASE;
					mother[j+1]--;
				}
			}
			ml -= (mother[ml-1] == 0);
			/*for(i=ml-1; i>=0; i--)
			{
				printf("%d", mother[i]);
			}
			printf("\n");*/
			son[0]--;
			for(j=0; j<sl; j++)
			{
				if(son[j] < 0)
				{
					son[j] += BASE;
					son[j+1]--;
				}
			}
			sl -= (son[sl-1] == 0);
			/*for(i=sl-1; i>=0; i--)
			{
				printf("%d", son[i]);
			}
			printf("\n");*/
			for(i=sl-1, bl=0; i>=0; i--)
			{
				for(j=bl++; j>0; j--)
				{
					buf[j] = buf[j-1];
				}
				buf[0] = son[i];
				/*if(i >= sl-20)
				{
					printf("START:\n");
					for(j=bl-1; j>=0; j--)
					{
						printf("%d", buf[j]);
					}
					printf("\n");
				}*/
				for(k=0; k<9; k++)
				{
					/*if(i >= sl-20)
					{
						printf("%d %d %d\n", bl, ml, comp(buf, bl, mother, ml));
					}*/
					if(comp(buf, bl, mother, ml) >= 0)
					{
						for(j=0; j<ml; j++)
						{
							buf[j] -= mother[j];
						}
						for(j=0; j<bl; j++)
						{
							if(buf[j] < 0)
							{
								buf[j] += BASE;
								buf[j+1]--;
							}
						}
						for(j=bl-1; j>=0&&buf[j]==0; j--);
						bl = j + 1;
						/*if(i >= sl-16)
						{
							printf("RES:");
							for(j=bl-1; j>=0; j--)
							{
								printf("%d", buf[j]);
							}
							printf("\n");
						}*/
					}
					else
					{
						break;
					}
				}
				/*if(i >= sl-20)
				{
					printf("XDDD %d\n", k);
					printf("END:\n");
					for(j=bl-1; j>=0; j--)
					{
						printf("%d", buf[j]);
					}
					printf("\n");
				}*/
				res[sl-i-1] = k + '0';
				if(bl == 1 && buf[0] == 0)
				{
					bl = 0;
				}
			}
			res[sl] = 0;
			for(i=0; i<sl&&res[i]=='0'; i++);
			if(strlen(res+i) >= 100)
			{
				printf("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits.\n", t, a, t, b);
			}
			else
			{
				printf("(%d^%d-1)/(%d^%d-1) %s\n", t, a, t, b, res+i);
			}
		}
	}
	return 0;
}
