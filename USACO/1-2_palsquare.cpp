/*
ID: sa072682
LANG: C
TASK: palsquare
*/

#include <stdio.h>

char trans(int now)
{
	if(now < 10)
	{
		return now + 48;
	}
	else
	{
		return now + 55;
	}
}

int main()
{
	int b, i, j, k, l;
	char temp[20], buf[20], ch;
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	scanf("%d", &b);
	for(i=1; i<301; i++)
	{
		j = i;
		l = 0;
		while(j)
		{
			temp[l++] = j % b;
			j /= b;
		}
		for(j=0, k=l-1; j<k; j++, k--)
		{
			ch = temp[j];
			temp[j] = temp[k];
			temp[k] = ch;
			temp[j] = trans(temp[j]);
			temp[k] = trans(temp[k]);
		}
		if(j == k)
		{
			temp[j] = trans(temp[j]);
		}
		temp[l] = 0;
		j = i * i;
		l = 0;
		while(j)
		{
			buf[l++] = j % b;
			j /= b;
		}
		for(j=0, k=l-1; j<k; j++, k--)
		{
			if(buf[j] != buf[k])
			{
				break;
			}
			buf[j] = trans(buf[j]);
			buf[k] = trans(buf[k]);
		}
		if(j == k)
		{
			buf[j] = trans(buf[j]);
		}
		buf[l] = 0;
		if(j >= k)
		{
			printf("%s %s\n", temp, buf);
		}
	}
	return 0;
}
