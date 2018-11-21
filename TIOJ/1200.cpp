#include <stdio.h>
#include <string.h>

char space[3005];
char star[3005];
char str[501][3005];
char *ptr[501];

int main()
{
	int cas, a, b, c, i, j, left, center, right;
	cas = 0;
	memset(space, ' ', sizeof(space));
	memset(star, '*', sizeof(star));
	space[1000] = star[1000] = 0;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if(!a && !b && !c)
		{
			break;
		}
		memset(str, ' ', sizeof(str));
		for(i=0; i<501; i++)
		{
			str[i][0] = 0;
			ptr[i] = str[i];
		}
		i = 500-a-a-2;
		sprintf(ptr[i], "%.*s\0", (a<<2)+2, star);
		ptr[i] += strlen(ptr[i]);
		for(i++, j=1, left=(a-1)*2, center=0, right=2*a-1; j<a; i++, j++, left-=2, center+=2)
		{
			sprintf(ptr[i], "*%.*s**%.*s*%.*s*\0", left, space, center, space, right, space);
			ptr[i] += strlen(ptr[i]);
		}
		sprintf(ptr[i], "***%.*s*%.*s*\0", center, space, right, star);
		ptr[i] += strlen(ptr[i]);
		i++;
		sprintf(ptr[i], "*%.*s*\0", a<<2, space);
		ptr[i] += strlen(ptr[i]);
		i++;
		sprintf(ptr[i], "*%.*s*%.*s*%.*s*\0", a, space, (a-1)<<1, star, a, space);
		ptr[i] += strlen(ptr[i]);
		i++;
		for(j=2; j<a; j++)
		{
			sprintf(ptr[i], "*%.*s*%.*s*%.*s*\0", a, space, (a-1)<<1, space, a, space);
			ptr[i] += strlen(ptr[i]);
			i++;
		}
		sprintf(ptr[i], "*%.*s*%.*s*%.*s*\0", a, star, (a-1)<<1, star, a, star);
		ptr[i] += strlen(ptr[i]);
		i++;
		for(i=500-b-1; i<501; i++)
		{
			str[i][strlen(str[i])] = ' ';
			ptr[i] = str[i] + (a<<2) + 4;
		}
		i = 500 - b - 1;
		sprintf(ptr[i], "* *\0");
		ptr[i] += strlen(ptr[i]);
		i++;
		sprintf(ptr[i], "** *\0");
		ptr[i] += strlen(ptr[i]);
		i++;
		for(j=3, left=3; j<b; j++, left++)
		{
			sprintf(ptr[i], "*%.*s*\0", left, space);
			ptr[i] += strlen(ptr[i]);
			i++;
		}
		sprintf(ptr[i], "*\0");
		ptr[i] += strlen(ptr[i]);
		i++;
		sprintf(ptr[i], "*\0");
		ptr[i] += strlen(ptr[i]);
		i++;
		for(i=500-c-1; i<501; i++)
		{
			str[i][strlen(str[i])] = ' ';
			ptr[i] = str[i] + (a<<2) + 4 + b + 2;
		}
		i = 500 - c - 1;
		sprintf(ptr[i], "%.*s\0", c+1, star);
		ptr[i] += strlen(ptr[i]);
		i++;
		for(j=1, left=c-1, right=1; j<c; j++, left--, right++)
		{
			sprintf(ptr[i], "%.*s*%.*s\0", left, space, right, space);
			ptr[i] += strlen(ptr[i]);
			i++;
		}
		sprintf(ptr[i], "%.*s\0", c+1, star);
		ptr[i] += strlen(ptr[i]);
		i++;
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0; i<500; i++)
		{
			if(str[i][0])
			{
				printf("%s\n", str[i]);
			}
		}
	}
	return 0;
}
