#include <stdio.h>

long long ary[10005];
char s[10005], s2[10005];

int main()
{
	int i, j, k;
	while (gets(s))
	{
		for (i=1; i<=10000; i++)
		{
			for (j=0, k=0; s[j]; j++)
			{
				sprintf(s2+k, "%d", i+(s[j]-'A'));
				while (s2[k])
				{
					ary[k] = s2[k]-'0';
					++k;
				}
			}
			while (k > 2)
			{
				if (k == 3 && ary[0]%10 == 1 && !(ary[1]%10) && !(ary[2]%10))
				{
					break;
				}
				for (j=0; j+1<k; j++)
				{
					ary[j] += ary[j+1];
				}
				--k;
			}
			if (k > 2)
			{
				printf("%d\n", i);
				break;
			}
		}
		if (i > 10000)
		{
			puts(":(");
		}
	}
	return 0;
}
