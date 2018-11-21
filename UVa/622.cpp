#include <stdio.h>

int stack1[10000], stack2[10000];
char str[10000];

int main()
{
	int count, i, isnum, num, isoperator, n1, n2;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		for(i=0, isnum=0, num=0, isoperator=0, n1=0, n2=0; str[i]; i++)
		{
			if(str[i] == '+' || str[i] == '*')
			{
				if(isnum)
				{
					stack2[n2++] = num;
					isnum = 0;
					num = 0;
				}
				else if(!i || isoperator)
				{
					break;
				}
				if(str[i] == '+')
				{
					for(; --n1>-1; )
					{
						if(stack1[n1] == '*')
						{
							stack2[n2++] = -stack1[n1];
						}
						else
						{
							break;
						}
					}
					stack1[++n1] = '+';
					n1++;
				}
				else
				{
					stack1[n1++] = '*';
				}
				isoperator = 1;
			}
			else if(str[i] == '(')
			{
				if(!isoperator && i && str[i-1] != '(')
				{
					break;
				}
				else
				{
					stack1[n1++] = '(';
				}
				isnum = isoperator = 0;
			}
			else if(str[i] == ')')
			{
				if(isoperator)
				{
					break;
				}
				else
				{
					if(isnum)
					{
						stack2[n2++] = num;
						num = 0;
					}
					for(; --n1>-1; )
					{
						if(stack1[n1] == '(')
						{
							break;
						}
						stack2[n2++] = -stack1[n1];
					}
					if(n1 == -1)
					{
						break;
					}
				}
				isnum = isoperator = 0;
			}
			else if(str[i] >= '0' && str[i] <= '9')
			{
				if(i && !isoperator && !isnum && str[i-1] != '(')
				{
					break;
				}
				else
				{
					isnum = 1;
					num *= 10;
					num += str[i] - 48;
				}
				isoperator = 0;
			}
			else
			{
				break;
			}
		}
		if(isnum)
		{
			stack2[n2++] = num;
		}
		if(!i || str[i] || isoperator)
		{
			printf("ERROR\n");
		}
		else
		{
			for(; --n1>-1; )
			{
				if(stack1[n1] == '(')
				{
					break;
				}
				stack2[n2++] = -stack1[n1];
			}
			if(n1 > -1)
			{
				printf("ERROR\n");
			}
			else
			{
				for(i=0, n1=0; i<n2; i++)
				{
					if(stack2[i] >= 0)
					{
						stack1[n1++] = stack2[i];
					}
					else
					{
						if(-stack2[i] == '+')
						{
							stack1[n1-2] += stack1[n1-1];
							n1--;
						}
						else
						{
							stack1[n1-2] *= stack1[n1-1];
							n1--;
						}
					}
				}
				printf("%d\n", stack1[0]);
			}
		}
	}
	return 0;
} 
