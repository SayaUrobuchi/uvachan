#include <stdio.h>

char s1[35], s2[35];

int main()
{
	unsigned int a, b, temp;
	int i, j, l1, l2;
	while(scanf("%u%u", &a, &b) == 2)
	{
		l1 = l2 = 0;
		temp = a;
		while(temp)
		{
			s1[l1++] = temp % 2;
			temp /= 2;
		}
		temp = b;
		while(temp)
		{
			s2[l2++] = temp % 2;
			temp /= 2;
		}
		if(!a)
		{
			printf("%d\n", l2);
		}
		else if(!b)
		{
			printf("%d\n", l1);
		}
		else
		{
			for(i=l1-1, j=l2-1; i>-1&&j>-1; i--, j--)
			{
				if(s1[i] != s2[j])
				{
					break;
				}
			}
			printf("%d\n", i+j+2);
		}
	}
	return 0;
}
