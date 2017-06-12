#include <stdio.h>
#include <string.h>

char plaintext[100];
char str[100];

char retrans(int now)
{
	if(!now)
	{
		return '_';
	}
	if(now == 27)
	{
		return '.';
	}
	return now + 96;
}

int trans(char ch)
{
	if(ch == '_')
	{
		return 0;
	}
	if(ch == '.')
	{
		return 27;
	}
	return ch - 96;
}

char decode(int now)
{
	int temp, temp2;
	temp = -now % 28;
	if(temp < 0)
	{
		temp += 28;
	}
	temp2 = trans(str[now]);
	if(temp2 < temp)
	{
		temp2 += 28;
	}
	/*printf("XDDD %d %d\n", temp2 - temp, temp);*/
	return retrans(temp2 - temp);
}

int main()
{
	int i, k, len;
	while(scanf("%d", &k) == 1)
	{
		if(!k)
		{
			break;
		}
		scanf("%s", str);
		len = strlen(str);
		for(i=0; i<len; i++)
		{
			plaintext[(k*i) % len] = decode(i);
			/*printf("%d %d\n", (k*i)%len, plaintext[(k*i)%len]);*/
		}
		plaintext[len] = 0;
		printf("%s\n", plaintext);
	}
	return 0;
}
