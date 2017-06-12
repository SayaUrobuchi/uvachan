#include <stdio.h>
#include <string.h>

char data[83682][6], tail[83682], len[83682], buf[6];

int getnum(int leng)
{
	int left, right, center, comp;
	left = 0;
	right = 83681;
	while(1)
	{
		center = left + right;
		center /= 2;
		if(len[center] == leng)
		{
			comp = strcmp(data[center], buf);
			if(!comp)
			{
				return center;
			}
			else if(comp > 0)
			{
				right = center - 1;
			}
			else
			{
				left = center + 1;
			}
			if(left > right)
			{
				return 0;
			}
		}
		else if(len[center] > leng)
		{
			right = center - 1;
		}
		else
		{
			left = center + 1;
		}
	}
}

int main()
{
	int i, j, k, l;
	data[0][0] = 0;
	tail[0] = 97;
	len[0] = 0;
	for(i=0, j=1; i<j; i++)
	{
		l = len[i];
		if(l == 5) break;
		for(k=tail[i]; k<123; k++)
		{
			sprintf(data[j], "%s%c", data[i], k);
			tail[j] = k + 1;
			len[j++] = l + 1;
		}
	}
	while(gets(buf))
	{
		printf("%d\n", getnum(strlen(buf)));
	}
	return 0;
}
