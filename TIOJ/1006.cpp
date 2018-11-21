#include <stdio.h>
#include <string.h>

int comp(char *s1, int n1, char *s2, int n2)
{
	if(n1 > n2)
	{
		return 1;
	}
	else if(n1 < n2)
	{
		return -1;
	}
	for(n1--; n1>-1; n1--)
	{
		if(s1[n1] > s2[n1])
		{
			return 1;
		}
		else if(s1[n1] < s2[n1])
		{
			return -1;
		}
	}
	return 0;
}

void decrease(char* s1, int n1, char* s2, int n2)
{
	int i;
	for(i=0; i<n2; i++)
	{
		s1[i] -= s2[i];
		if(s1[i] < 0)
		{
			s1[i] += 10;
			s1[i+1]--;
		}
	}
	for(; i<n1; i++)
	{
		if(s1[i] < 0)
		{
			s1[i] += 10;
			s1[i+1]--;
		}
	}
}

int main()
{
	int n1, n2, n, rn, i, j, k, l, res[51];
	char s1[51], s2[51], str[51];
	while(scanf("%s%s", s1, s2) == 2)
	{
		n1 = strlen(s1);
		n2 = strlen(s2);
		for(i=0, j=n2-1; i<j; i++, j--)
		{
			k = s2[i];
			s2[i] = s2[j];
			s2[j] = k;
		}
		for(i=0; i<n1; i++)
		{
			s1[i] -= 48;
		}
		for(i=0; i<n2; i++)
		{
			s2[i] -= 48;
		}
		for(i=0, n=0; i<n1; i++)
		{
			for(j=n; j; j--)
			{
				str[j] = str[j-1];
			}
			str[0] = s1[i];
			n++;
			k = 0;
			while(comp(str, n, s2, n2) >= 0)
			{
				decrease(str, n, s2, n2);
				for(j=n-1; j>-1&&!str[j]; j--);
				n = j + 1;
				k++;
			}
			res[i] = k;
		}
		for(i=0; i<n1&&!res[i]; i++);
		if(i == n1)
		{
			printf("0");
		}
		for(; i<n1; i++)
		{
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}
