#include <stdio.h>
#include <string.h>

int tbl[26];
int temptbl[26];
char str[1000];

int uppercase(char now)
{
	return now > 64 && now < 91;
}

int digit(char now)
{
	return now > 47 && now < 58;
}

int opera(char now)
{
	return now == '=' || now == '+' || now == '-' || now == '*' || now == '/';
}

int recursion(int left, int right)
{
	int i, j, l, r, field, result, neg, temp, ch, ope, count;
	for(i=left, field=0, result=0, neg=0, ch=-1, l=r=-1; i<=right; i++)
	{
		if(!field)
		{
			if(str[i] == '(')
			{
				for(j=i+1, count=1; j<=right; j++)
				{
					if(str[j] == '(')
					{
						count++;
					}
					else if(str[j] == ')')
					{
						count--;
					}
					if(!count)
					{
						break;
					}
				}
				l = i + 1;
				r = j - 1;
				i = j;
				if(neg)
				{
					result = -result;
				}
			}
			else if(uppercase(str[i]))
			{
				ch = str[i] - 65;
			}
			else if(digit(str[i]))
			{
				result *= 10;
				result += str[i] - 48;
			}
			else if(opera(str[i]))
			{
				ope = str[i];
				field++;
			}
			else if(str[i] == '_')
			{
				neg = 1;
			}
		}
		else
		{
			temp = recursion(i, right);
			if(l != -1 && r != -1)
			{
				result = recursion(l, r);
			}
			l = r = -1;
			if(ch != -1)
			{
				result = tbl[ch];
			}
			if(neg)
			{
				result = -result;
				neg = 0;
			}
			if(ope == '=')
			{
				tbl[ch] = result = temp;
			}
			else if(ope == '+')
			{
				result += temp;
			}
			else if(ope == '-')
			{
				result -= temp;
			}
			else if(ope == '*')
			{
				result *= temp;
			}
			else
			{
				result /= temp;
			}
			ch = -1;
			break;
		}
	}
	if(l != -1 && r != -1)
	{
		result = recursion(l, r);
	}
	if(ch != -1)
	{
		result = tbl[ch];
	}
	if(neg)
	{
		result = -result;
	}
	/*printf("%d %d: %d\n", left, right, result);*/
	return result;
}

int main()
{
	int i, chk;
	while(gets(str))
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		recursion(0, strlen(str)-1);
		for(i=0, chk=0; i<26; i++)
		{
			if(tbl[i] != temptbl[i])
			{
				if(chk)
				{
					printf(", ");
				}
				chk = 1;
				printf("%c = %d", i+65, tbl[i]);
				temptbl[i] = tbl[i];
			}
		}
		if(chk)
		{
			printf("\n");
		}
		else
		{
			printf("No Change\n");
		}
	}
	return 0;
}
