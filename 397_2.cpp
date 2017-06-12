#include <stdio.h>

int n;
int ary[30];
char opera[30];
char variable[20];
char str[10000];

int isdig(char now)
{
	return now > 47 && now < 58;
}

void print()
{
	int i;
	printf("%d", ary[0]);
	for(i=0; i<n; i++)
	{
		printf("  %c     %d", opera[i], ary[i+1]);
	}
	printf(" =              %s\n", variable);
}

int main()
{
	int cas, i, j, isnum, neg, num;
	cas = 0;
	while(gets(str))
	{
		for(i=0, j=0, isnum=0, neg=0, num=0; str[i]; i++)
		{
			if((str[i] == '-' || str[i] == '+') && !isnum)
			{
				neg = (str[i] == '-');
			}
			else if(isdig(str[i]))
			{
				num *= 10;
				num += str[i] - 48;
				isnum = 1;
			}
			else if(str[i] != ' ')
			{
				opera[j] = str[i];
				if(neg)
				{
					num = -num;
				}
				ary[j] = num;
				neg = num = isnum = 0;
				j++;
				if(str[i] == '=')
				{
					sscanf(str+i+1, "%s", variable);
					break;
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		n = j - 1;
		print();
		for(i=0; i<n; )
		{
			if(opera[i] == '*')
			{
				ary[i] *= ary[i+1];
				for(j=i+1; j<n; j++)
				{
					opera[j-1] = opera[j];
					ary[j] = ary[j+1];
				}
				n--;
				print();
			}
			else if(opera[i] == '/')
			{
				ary[i] /= ary[i+1];
				for(j=i+1; j<n; j++)
				{
					opera[j-1] = opera[j];
					ary[j] = ary[j+1];
				}
				n--;
				print();
			}
			else
			{
				i++;
			}
		}
		for(i=0; i<n; )
		{
			if(opera[i] == '+')
			{
				ary[i] += ary[i+1];
				for(j=i+1; j<n; j++)
				{
					opera[j-1] = opera[j];
					ary[j] = ary[j+1];
				}
				n--;
				print();
			}
			else if(opera[i] == '-')
			{
				ary[i] -= ary[i+1];
				for(j=i+1; j<n; j++)
				{
					opera[j-1] = opera[j];
					ary[j] = ary[j+1];
				}
				n--;
				print();
			}
			else
			{
				i++;
			}
		}
	}
	return 0;
}
