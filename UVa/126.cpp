#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int neg1[101], neg2[101], coe[10201], coe1[101], coe2[101];
int exx[10201], exx1[101], exx2[101], exy[10201], exy1[101], exy2[101], index[10201];
char str[1001], ans1[1001], ans2[1001];

int comp(const void *p, const void *q)
{
	int i, j;
	i = *(int*)p;
	j = *(int*)q;
	if(exx[i] == exx[j])
	{
		return exy[i] - exy[j];
	}
	return exx[j] - exx[i];
}

int main()
{
	int n, i, j, k, p, l1, l2, x, y, cx, cy, num, negative, *ptr, next;
	while(gets(str))
	{
		if(str[0] == '#')
		{
			break;
		}
		for(i=0, k=0, num=0, x=0, y=0, cx=0, cy=0, negative=0, ptr=&num; str[i]; i++)
		{
			if(str[i] == '-' || str[i] == '+')
			{
				if(i)
				{
					if(!num)
					{
						num = 1;
					}
					neg1[k] = negative;
					coe1[k] = num;
					if(cx && !x)
					{
						exx1[k] = 1;
					}
					else
					{
						exx1[k] = x;
					}
					if(cy && !y)
					{
						exy1[k] = 1;
					}
					else
					{
						exy1[k] = y;
					}
					k++;
				}
				negative = (str[i] == '-');
				num = x = y = cx = cy = 0;
				ptr = &num;
			}
			else if(str[i] == 'x')
			{
				cx = 1;
				ptr = &x;
			}
			else if(str[i] == 'y')
			{
				ptr = &y;
				cy = 1;
			}
			else
			{
				*ptr *= 10;
				*ptr += str[i] - 48;
			}
		}
		if(i)
		{
			if(!num)
			{
				num = 1;
			}
			neg1[k] = negative;
			coe1[k] = num;
			if(cx && !x)
			{
				exx1[k] = 1;
			}
			else
			{
				exx1[k] = x;
			}
			if(cy && !y)
			{
				exy1[k] = 1;
			}
			else
			{
				exy1[k] = y;
			}
			k++;
		}
		l1 = k;
		gets(str);
		for(i=0, k=0, num=0, x=0, y=0, cx=0, cy=0, negative=0, ptr=&num; str[i]; i++)
		{
			if(str[i] == '-' || str[i] == '+')
			{
				if(i)
				{
					if(!num)
					{
						num = 1;
					}
					neg2[k] = negative;
					coe2[k] = num;
					if(cx && !x)
					{
						exx2[k] = 1;
					}
					else
					{
						exx2[k] = x;
					}
					if(cy && !y)
					{
						exy2[k] = 1;
					}
					else
					{
						exy2[k] = y;
					}
					k++;
				}
				negative = (str[i] == '-');
				num = x = y = cx = cy = 0;
				ptr = &num;
			}
			else if(str[i] == 'x')
			{
				cx = 1;
				ptr = &x;
			}
			else if(str[i] == 'y')
			{
				cy = 1;
				ptr = &y;
			}
			else
			{
				*ptr *= 10;
				*ptr += str[i] - 48;
			}
		}
		if(i)
		{
			if(!num)
			{
				num = 1;
			}
			neg2[k] = negative;
			coe2[k] = num;
			if(cx && !x)
			{
				exx2[k] = 1;
			}
			else
			{
				exx2[k] = x;
			}
			if(cy && !y)
			{
				exy2[k] = 1;
			}
			else
			{
				exy2[k] = y;
			}
			k++;
		}
		l2 = k;
		for(i=0, k=0; i<l1; i++)
		{
			for(j=0; j<l2; j++)
			{
				coe[k] = coe1[i] * coe2[j];
				if(neg1[i]^neg2[i])
				{
					coe[k] = -coe[k];
				}
				exx[k] = exx1[i] + exx2[j];
				exy[k] = exy1[i] + exy2[j];
				index[k] = k;
				k++;
			}
		}
		memset(ans1, ' ', sizeof(ans1));
		memset(ans2, ' ', sizeof(ans2));
		qsort(index, k, sizeof(int), comp);
		for(p=0, j=0; p<k; p=next)
		{
			i = index[p];
			for(next=p+1; next<k; next++)
			{
				if(exx[index[next]] != exx[i] || exy[index[next]] != exy[i])
				{
					break;
				}
				coe[i] += coe[index[next]];
			}
			if(!coe[i])
			{
				continue;
			}
			if(coe[i] < 0)
			{
				if(j)
				{
					ans2[j] = 0;
					strcat(ans2, " - ");
					j += 3;
					ans2[j] = ' ';
				}
				else
				{
					ans2[j] = '-';
					j++;
				}
				coe[i] = -coe[i];
			}
			else
			{
				if(j)
				{
					ans2[j] = 0;
					strcat(ans2, " + ");
					j += 3;
					ans2[j] = ' ';
				}
			}
			if(coe[i] > 1)
			{
				sprintf(str, "%d", coe[i]);
				ans2[j] = 0;
				strcat(ans2, str);
				j += strlen(str);
				ans2[j] = ' ';
			}
			if(exx[i])
			{
				ans2[j++] = 'x';
				if(exx[i] > 1)
				{
					sprintf(str, "%d", exx[i]);
					ans1[j] = 0;
					strcat(ans1, str);
					j += strlen(str);
					ans1[j] = ' ';
				}
			}
			if(exy[i])
			{
				ans2[j++] = 'y';
				if(exy[i] > 1)
				{
					sprintf(str, "%d", exy[i]);
					ans1[j] = 0;
					strcat(ans1, str);
					j += strlen(str);
					ans1[j] = ' ';
				}
			}
			if(!exx[i] && !exy[i] && coe[i] == 1)
			{
				ans2[j++] = '1';
			}
		}
		ans1[j] = ans2[j] = 0;
		printf("%s\n%s\n", ans1, ans2);
	}
	return 0;
}
