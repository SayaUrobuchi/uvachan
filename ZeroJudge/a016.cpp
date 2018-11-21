#include <stdio.h>
#include <string.h>

int len1, len2;
int ary1[200000], ary2[200000];
int buf[200000];
char s1[200000], s2[200000];
char ope[200000];

void reverse(char* s, int len)
{
	int i, j, temp;
	for(i=0, j=len-1; i<j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int comp(int *a1, int *a2, int len)
{
	int i;
	for(i=len-1; i>-1; i--)
	{
		if(a1[i] > a2[i])
		{
			return 1;
		}
		else if(a1[i] < a2[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j, k, temp, n1, n2;
	while(scanf("%s%s%s", s1, ope, s2) == 3)
	{
		memset(ary1, 0, sizeof(ary1));
		memset(ary2, 0, sizeof(ary2));
		if(ope[0] == '+')
		{
			len1 = strlen(s1);
			len2 = strlen(s2);
			reverse(s1, len1);
			reverse(s2, len2);
			for(i=0, temp=0; i<len1; i+=9, temp++)
			{
				for(j=0, k=1, ary1[temp]=0; j<9&&i+j<len1; j++, k*=10)
				{
					ary1[temp] += k * (s1[i+j] - 48);
				}
			}
			n1 = temp;
			for(i=0, temp=0; i<len2; i+=9, temp++)
			{
				for(j=0, k=1, ary2[temp]=0; j<9&&i+j<len2; j++, k*=10)
				{
					ary2[temp] += k * (s2[i+j] - 48);
				}
			}
			n2 = temp;
			for(i=0; i<n2; i++)
			{
				ary1[i] += ary2[i];
				if(ary1[i] > 999999999)
				{
					ary1[i+1]++;
					ary1[i] -= 1000000000;
				}
			}
			for(; i<n1; i++)
			{
				if(ary1[i] > 999999999)
				{
					ary1[i+1]++;
					ary1[i] -= 1000000000;
				}
			}
			for(; ary1[i]; i++);
			printf("%d", ary1[i-1]);
			for(j=i-2; j>-1; j--)
			{
				printf("%09d", ary1[j]);
			}
			printf("\n");
		}
		else if(ope[0] == '-')
		{
			len1 = strlen(s1);
			len2 = strlen(s2);
			reverse(s1, len1);
			reverse(s2, len2);
			for(i=0, temp=0; i<len1; i+=9, temp++)
			{
				for(j=0, k=1, ary1[temp]=0; j<9&&i+j<len1; j++, k*=10)
				{
					ary1[temp] += k * (s1[i+j] - 48);
				}
			}
			n1 = temp;
			for(i=0, temp=0; i<len2; i+=9, temp++)
			{
				for(j=0, k=1, ary2[temp]=0; j<9&&i+j<len2; j++, k*=10)
				{
					ary2[temp] += k * (s2[i+j] - 48);
				}
			}
			n2 = temp;
			temp = 0;
			if(n1 < n2 || (n1 == n2 && !comp(ary1, ary2, n1)))
			{
				memcpy(buf, ary1, sizeof(buf));
				memcpy(ary1, ary2, sizeof(buf));
				memcpy(ary2, buf, sizeof(buf));
				temp = 1;
			}
			for(i=0; i<n2; i++)
			{
				ary1[i] -= ary2[i];
				if(ary1[i] < 0)
				{
					ary1[i+1]--;
					ary1[i] += 1000000000;
				}
			}
			for(; i<n1; i++)
			{
				if(ary1[i] < 0)
				{
					ary1[i+1]--;
					ary1[i] += 1000000000;
				}
			}
			for(; !ary1[i]&&i>-1; i--);
			if(i == -1)
			{
				printf("0\n");
			}
			else
			{
				if(temp)
				{
					printf("-");
				}
				printf("%d", ary1[i]);
				for(j=i-1; j>-1; j--)
				{
					printf("%09d", ary1[j]);
				}
				printf("\n");
			}
		}
		else if(ope[0] == '*')
		{
			len1 = strlen(s1);
			len2 = strlen(s2);
			reverse(s1, len1);
			reverse(s2, len2);
			for(i=0, temp=0; i<len1; i+=4, temp++)
			{
				for(j=0, k=1, ary1[temp]=0; j<4&&i+j<len1; j++, k*=10)
				{
					ary1[temp] += k * (s1[i+j] - 48);
				}
			}
			n1 = temp;
			for(i=0, temp=0; i<len2; i+=4, temp++)
			{
				for(j=0, k=1, ary2[temp]=0; j<4&&i+j<len2; j++, k*=10)
				{
					ary2[temp] += k * (s2[i+j] - 48);
				}
			}
			n2 = temp;
			memset(buf, 0, sizeof(buf));
			for(i=0; i<n1; i++)
			{
				for(j=0, k=i; j<n2; j++, k++)
				{
					buf[k] += ary1[i] * ary2[j];
					if(buf[k] > 9999)
					{
						buf[k+1] += buf[k] / 10000;
						buf[k] %= 10000;
					}
				}
			}
			for(i=0; i<n1+n2-1; i++)
			{
				if(buf[i] > 9999)
				{
					buf[i+1] += buf[i] / 10000;
					buf[i] %= 10000;
				}
			}
			for(; buf[i]; i++)
			{
				if(buf[i] > 9999)
				{
					buf[i+1] += buf[i] / 10000;
					buf[i] %= 10000;
				}
			}
			printf("%d", buf[i-1]);
			for(j=i-2; j>-1; j--)
			{
				printf("%04d", buf[j]);
			}
			printf("\n");
		}
		else
		{
			len1 = strlen(s1);
			len2 = strlen(s2);
			memset(buf, 0, sizeof(buf));
			for(i=0; i<len2; i++)
			{
				ary1[i] = s1[len2-i-1] - 48;
			}
			n1 = len2;
			for(i=0; i<len2; i++)
			{
				ary2[i] = s2[len2-i-1] - 48;
			}
			for(i=0; i+len2<=len1; i++)
			{
				while(n1 > len2 || (n1 == len2 && comp(ary1, ary2, len2)))
				{
					buf[i]++;
					for(j=0; j<len2; j++)
					{
						ary1[j] -= ary2[j];
						if(ary1[j] < 0)
						{
							for(; ary1[j] < 0; ary1[j] += 10, ary1[j+1]--);
						}
					}
					for(; j<n1; j++)
					{
						if(ary1[j] < 0)
						{
							for(; ary1[j] < 0; ary1[j] += 10, ary1[j+1]--);
						}
					}
					if(!ary1[n1-1])
					{
						n1--;
					}
				}
				if(i+len2 < len1)
				{
					for(j=n1; j>0; j--)
					{
						ary1[j] = ary1[j-1];
					}
					ary1[0] = s1[i+len2] - 48;
					n1++;
					for(j=n1; j>-1&&!ary1[j]; j--);
					n1 = j + 1;
				}
			}
			for(j=0; !buf[j]&&j+len2<=len1; j++);
			if(j+len2 > len1)
			{
				printf("0\n");
			}
			else
			{
				for(; j+len2<=len1; j++)
				{
					printf("%d", buf[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
