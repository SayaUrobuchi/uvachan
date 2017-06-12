#include <stdio.h>

int ary[101][5];
char str[1001];

int encode(char ch)
{
	if(ch == 'r')
	{
		return 0;
	}
	if(ch == 'o')
	{
		return 1;
	}
	if(ch == 'y')
	{
		return 2;
	}
	if(ch == 'g')
	{
		return 3;
	}
	return 4;
}

int main()
{
	int n, i, j, k, sum, ans, winner;
	while(gets(str))
	{
		if(str[0] == '#')
		{
			break;
		}
		n = 0;
		do
		{
			for(i=2; i<19; i+=4)
			{
				ary[n][encode(str[i-2])] = str[i];
			}
			n++;
		}while(gets(str) && str[0] != 'e');
		for(i=0, ans=1000000000; i<n; i++)
		{
			for(j=0, sum=0; j<n; j++)
			{
				for(k=0; k<5; k++)
				{
					sum += (ary[i][k] != ary[j][k]);
				}
			}
			if(sum < ans)
			{
				ans = sum;
				winner = i;
			}
		}
		printf("%d\n", winner+1);
	}
	return 0;
}
