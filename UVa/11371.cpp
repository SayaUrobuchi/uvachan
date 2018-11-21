#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[2008], buf2[2008];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

int main()
{
	int n, i, l, temp;
	long long n1, n2;
	while(scanf("%d", &n) == 1)
	{
		sprintf(buf, "%d\0", n);
		qsort(buf, l=strlen(buf), sizeof(char), comp);
		for(i=0, temp=-1; i<l; i++)
		{
			buf2[i] = buf[l-i-1];
			if(temp == -1 && buf[i] != '0')
			{
				temp = i;
			}
		}
		buf2[i] = 0;
		i = temp;
		temp = buf[i];
		buf[i] = buf[0];
		buf[0] = temp;
		/*puts(buf);
		puts(buf2);*/
		sscanf(buf, "%lld", &n1);
		sscanf(buf2, "%lld", &n2);
		printf("%lld - %lld = %lld = 9 * %lld\n", n2, n1, n2-n1, (n2-n1)/9);
	}
	return 0;
}
