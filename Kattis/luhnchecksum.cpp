#include <stdio.h>

char s[1048576];

int main()
{
	int count, len, i, t, sum;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (len=0; s[len]; len++);
		for (i=0, sum=0; s[i]; i++)
		{
			t = s[i] - '0';
			if ((i&1) == (len&1))
			{
				t <<= 1;
				sum += t/10 + t%10;
			}
			else
			{
				sum += t;
			}
		}
		puts(sum%10?"FAIL":"PASS"); 
	}
	return 0;
}
