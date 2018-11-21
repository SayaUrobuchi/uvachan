#include <stdio.h>
#include <string.h>

int dp[35];
char ch[5] = {'|', 'n', '9', '8', 'r'};
char str[1000];
char buf[150];

int trans()
{
	int result;
	char *ptr;
	result = 0;
	ptr = strtok(str, " ");
	do
	{
		if(*ptr == '|')
		{
			result += strlen(ptr);
		}
		else if(*ptr == 'n')
		{
			result += strlen(ptr) * 10;
		}
		else if(*ptr == '9')
		{
			result += strlen(ptr) * 100;
		}
		else if(*ptr == '8')
		{
			result += strlen(ptr) * 1000;
		}
		else
		{
			result += strlen(ptr) * 10000;
		}
	}while(ptr=strtok(NULL, " "));
	return result;
}

void sprint(char *s, int now, int star, int ends)
{
	int i, j, temp;
	for(i=0, j=0; now; j++, now/=10)
	{
		if(temp=now%10)
		{
			memset(s+i, ch[j], temp);
			i += temp + 1;
		}
	}
	if(star)
	{
		s[i] = '*';
		i += 2;
	}
	s[i-1] = ends;
}

int main()
{
	int i, j, a, b, temp;
	dp[0] = 1;
	for(i=1; i<31; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	while(gets(str))
	{
		if(!str[0])
		{
			break;
		}
		a = trans();
		if(gets(str))
		{
			b = trans();
			for(j=30; j>-1&&dp[j]>b; j--);
			for(i=0, temp=a; i<=j; i++, temp+=temp)
			{
				memset(buf, ' ', sizeof(buf));
				sprint(buf, dp[i]%100000, b&dp[i], ' ');
				sprint(buf+34, temp%=100000, 0, 0);
				printf("%s\n", buf);
			}
			memset(buf, ' ', sizeof(buf));
			sprint(buf, (int)((((long long)a)*b)%100000), 0, 0);
			printf("The solution is: %s\n", buf);
		}
		else
		{
			break;
		}
	}
	return 0;
}
