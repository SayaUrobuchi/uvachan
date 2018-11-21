#include <stdio.h>

int ary[11];
char str[1000];

int decode(char ch)
{
	if(ch <= 'H')
	{
		return ch - 55;
	}
	else if(ch == 'I')
	{
		return 34;
	}
	else if(ch <= 'N')
	{
		return ch - 56;
	}
	else if(ch == 'O')
	{
		return 35;
	}
	else if(ch <= 'V')
	{
		return ch - 57;
	}
	else if(ch == 'W')
	{
		return 32;
	}
	else if(ch <= 'Y')
	{
		return ch - 58;
	}
	else
	{
		return 33;
	}
}

int main()
{
	int temp, i, result;
	while(gets(str))
	{
		temp = decode(str[0]);
		ary[0] = temp / 10;
		ary[1] = temp % 10;
		for(i=1; str[i]; i++)
		{
			ary[i+1] = str[i] - 48;
		}
		for(i=1, result=ary[0]; i<10; i++)
		{
			result += ary[i] * (10-i);
		}
		result += ary[i];
		if(result % 10)
		{
			printf("fake\n");
		}
		else
		{
			printf("real\n");
		}
	}
	return 0;
}
