#include <stdio.h>
#include <string.h>

int num[1000], buf[1000], temp[1000], size[20], sum[20][1000], n;
char str[100], stack[1000];

void decrease(int* now, int dec, int len)
{
	int i;
	now[len-1] -= dec;
	for(i=len-1; i; i--)
	{
		if(now[i] < 0)
		{
			now[i] += 10;
			now[i-1]--;
		}
	}
}

void calc(int degree, int times)
{
	int i;
	if(size[degree] > n)
	{
		n = size[degree];
	}
	for(i=0; i<n; i++)
	{
		num[i] += sum[degree][i] * times;
		if(num[i] > 9)
		{
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	for(; num[i]; i++)
	{
		if(num[i] > 9)
		{
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	n = i;
}

int main()
{
	int i, j, k, l, len, ltemp;
	sum[0][0] = size[0] = 1;
	for(i=1; i<20; i++)
	{
		for(j=0; j<size[i-1]; j++)
		{
			sum[i][j] += sum[i-1][j] * 26;
			if(sum[i][j] > 9)
			{
				sum[i][j+1] += sum[i][j] / 10; 
				sum[i][j] %= 10;
			}
		}
		for(; sum[i][j]; j++)
		{
			if(sum[i][j] > 9)
			{
				sum[i][j+1] += sum[i][j] / 10;
				sum[i][j] %= 10;
			}
		}
		size[i] = j;
	}
	while(gets(str))
	{
		if(str[0] == '*')
		{
			break;
		}
		else if(str[0] < 65)
		{
			for(i=0; str[i]; i++)
			{
				temp[i] = (num[i] = str[i]- 48);
			}
			ltemp = len = strlen(str);
			for(i=0, j=len-1; i<j; i++, j--)
			{
				k = num[i];
				num[i] = num[j];
				num[j] = k;
			}
			/*decrease(temp, 1, len);*/
			l = 0;
			while(1)
			{
				buf[0] = 0;
				for(i=0, n=0; i<len; i++)
				{
					n *= 10;
					n += temp[i];
					if(n >= 26)
					{
						buf[0] = n / 26;
						n %= 26;
						i++;
						break;
					}
				}
				for(k=1; i<len; i++, k++)
				{
					n *= 10;
					n += temp[i];
					buf[k] = n / 26;
					n %= 26;
				}
				/*for(i=0; i<k; i++)
				{
					printf("%d", buf[i]);
				}
				printf("\n");*/
				if(!n)
				{
					stack[l++] = 'z';
					if(buf[0] == 1)
					{
						break;
					}
				}
				else
				{
					stack[l++] = n+96;
				}
				if(k == 1 && !buf[k-1])
				{
					break;
				}
				for(i=0; i<k; i++)
				{
					temp[i] = buf[i];
				}
				len = k;
			}
			for(i=l-1; i>-1; i--)
			{
				printf("%c", stack[i]);
			}
			for(; l<22; l++)
			{
				printf(" ");
			}
			for(i=ltemp-1; i>-1; i--)
			{
				if(i != ltemp-1 && !((i+1)%3))
				{
					printf(",");
				}
				printf("%d", num[i]);
			}
			printf("\n");
		}
		else
		{
			printf("%s", str);
			for(i=len=strlen(str); i<22; i++)
			{
				printf(" ");
			}
			for(i=0, j=len-1; i<j; i++, j--)
			{
				k = str[i];
				str[i] = str[j];
				str[j] = k;
			}
			memset(num, 0, sizeof(num));
			n = 1;
			for(i=0; i<len; i++)
			{
				calc(i, str[i]-96);
			}
			for(i=n-1; i>-1; i--)
			{
				if(i != n-1 && !((i+1)%3))
				{
					printf(",");
				}
				printf("%d", num[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
