#include <stdio.h>
#include <string.h>

char s[1000005], *ptr;

int main()
{
	int id;
	double res, num;
	while(gets(s))
	{
		res = 0.0;
		ptr = strtok(s, " ");
		do
		{
			sscanf(ptr, "%d:%lf", &id, &num);
			if(id & 1)
			{
				res += num;
			}
			else
			{
				res -= num;
			}
		}while(ptr=strtok(NULL, " "));
		printf("%g\n", res);
	}
	return 0;
}
