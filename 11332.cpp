#include <stdio.h>

int recursion(int n)
{
	int temp;
	if(n < 10)
	{
		return n;
	}
	temp = 0;
	for(; n; n/=10)
	{
		temp += n % 10;
	}
	return recursion(temp);
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("%d\n", recursion(n));
	}
	return 0;
}
