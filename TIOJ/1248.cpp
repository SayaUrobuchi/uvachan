#include <stdio.h>
#include <string.h>

#define BASE9 1000000000
#define BASE4 10000

int a1[300], a2[300], temp[600];
char s1[2000], s2[2000], op[10], format[20], res[2000];

int max(int p, int q)
{
	return p > q ? p : q;
}

void trans(char *s, int *a, int *l, int step)
{
	int i;
	memset(a, 0, sizeof(a1));
	sprintf(format, "%%%dd\0", step);
	for(i=strlen(s)-step, *l=0; i>0; i-=step, (*l)++)
	{
		sscanf(s+i, format, &a[*l]);
	}
	sprintf(format, "%%%dd\0", step+i);
	sscanf(s, format, &a[(*l)++]);
}

int cmp(char *p, char *q, int l1, int l2)
{
	if(l1 != l2)
	{
		return l1-l2;
	}
	return strcmp(p, q);
}

int main()
{
	int i, j, k, l, l1, l2, *p, *q;
	while(scanf("%s%s%s", s1, op, s2) == 3)
	{
		if(strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0)
		{
			break;
		}
		if(*op == '+')
		{
			trans(s1, a1, &l1, 9);
			trans(s2, a2, &l2, 9);
			for(i=0, l=max(l1, l2); i<l; i++)
			{
				a1[i] += a2[i];
				if(a1[i] >= BASE9)
				{
					a1[i] -= BASE9;
					a1[i+1]++;
				}
			}
			if(a1[i] >= BASE9)
			{
				a1[i+1]++;
				a1[i] -= BASE9;
				i++;
			}
			if(a1[i])
			{
				i++;
			}
			printf("%d", a1[i-1]);
			for(i-=2; i>=0; i--)
			{
				printf("%09d", a1[i]);
			}
			printf("\n");
		}
		else if(*op == '-')
		{
			trans(s1, a1, &l1, 9);
			trans(s2, a2, &l2, 9);
			if(cmp(s1, s2, strlen(s1), strlen(s2)) >= 0)
			{
				p = a1;
				q = a2;
			}
			else
			{
				printf("-");
				p = a2;
				q = a1;
				i = l1;
				l1 = l2;
				l2 = i;
			}
			for(i=0; i<l1; i++)
			{
				p[i] -= q[i];
				if(p[i] < 0)
				{
					p[i] += BASE9;
					p[i+1]--;
				}
			}
			for(i=l1-1; i>=0&&!p[i]; i--);
			if(i == -1)
			{
				printf("0");
			}
			else
			{
				printf("%d", p[i]);
				for(i--; i>=0; i--)
				{
					printf("%09d", p[i]);
				}
			}
			printf("\n");
		}
		else if(*op == '*')
		{
			trans(s1, a1, &l1, 4);
			trans(s2, a2, &l2, 4);
			memset(temp, 0, sizeof(temp));
			for(i=0; i<l1; i++)
			{
				for(j=0; j<l2; j++)
				{
					temp[i+j] += a1[i] * a2[j];
					if(temp[i+j] >= BASE4)
					{
						temp[i+j+1] += temp[i+j] / BASE4;
						temp[i+j] %= BASE4;
					}
				}
			}
			for(i=0, j=l1+l2-1; i<j; i++)
			{
				if(temp[i] >= BASE4)
				{
					temp[i+1] += temp[i] / BASE4;
					temp[i] %= BASE4;
				}
			}
			for(; temp[i]; i++)
			{
				if(temp[i] >= BASE4)
				{
					temp[i+1] += temp[i] / BASE4;
					temp[i] %= BASE4;
				}
			}
			printf("%d", temp[i-1]);
			for(i-=2; i>=0; i--)
			{
				printf("%04d", temp[i]);
			}
			printf("\n");
		}
		else
		{
			for(l1=0; s1[l1]; s1[l1++]-=48);
			for(l2=0; s2[l2]; s2[l2++]-=48);
			res[0] = 48;
			for(i=l2-1, l=0; i<l1; i++, l++)
			{
				for(res[l]=48; ; res[l]++)
				{
					j = i-l2+1;
					if(j && s1[j-1])
					{
					}
					else
					{
						for(k=0; k<l2; j++, k++)
						{
							if(s1[j] != s2[k])
							{
								break;
							}
						}
						if(k < l2 && s1[j] < s2[k])
						{
							break;
						}
					}
					for(k=l2-1, j=i; k>=0; k--, j--)
					{
						s1[j] -= s2[k];
						if(s1[j] < 0)
						{
							s1[j] += 10;
							s1[j-1]--;
						}
					}
				}
			}
			l += (l==0);
			res[l] = 0;
			for(i=0; i<l1&&s1[i]==0; i++);
			if(res[0] == 48 && l > 1)
			{
				printf("%s", res+1);
			}
			else
			{
				printf("%s", res);
			}
			printf("...");
			for(j=0; i<l1; i++, j=1)
			{
				printf("%d", s1[i]);
			}
			if(j == 0)
			{
				printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}
