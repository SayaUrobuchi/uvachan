#include <stdio.h>
#include <string.h>

char str[100];

int main()
{
	int count, h, m, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d:%d", &h, &m);
		for(m++; ; m++)
		{
			if(m >= 60)
			{
				m = 0;
				h++;
				if(h == 24)
				{
					h = 0;
				}
			}
			sprintf(str, "%d", h*100+m);
			for(i=0, j=strlen(str)-1; i<j; i++, j--)
			{
				if(str[i] != str[j])
				{
					break;
				}
			}
			if(i >= j)
			{
				printf("%02d:%02d\n", h, m);
				break;
			}
		}
	}
	return 0;
}
