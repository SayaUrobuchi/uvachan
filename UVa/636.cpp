#include <stdio.h>
#include <math.h>

char str[10000];

int main()
{
	int n, i, b, len, temp, result;
	while(gets(str))
	{
		if(str[0] == '0')
		{
			break;
		}
		for(i=0, b=0; str[i]; i++)
		{
			if((str[i] -= 48) > b)
			{
				b = str[i];
			}
		}
		len = i;
		for(b++; ; b++)
		{
			for(i=len-1, temp=1, result=0; i>-1; i--, temp*=b)
			{
				result += str[i] * temp;
			}
			temp = sqrt(result) + 0.00001;
			if(temp * temp == result)
			{
				printf("%d\n", b);
				break;
			}
		}
	}
	return 0;
}
