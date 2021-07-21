#include <iostream>
using namespace std;

string hundred[] = {"", "onehundred", "twohundred", "threehundred", "fourhundred", 
					"fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
string sp[] = {"", "eleven", "twelve", "thirteen", "fourteen", 
			   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string ten[] = {"", "", "twenty", "thirty", "forty", 
				"fifty", "sixty", "seventy", "eighty", "ninety"};
string one[] = {"", "one", "two", "three", "four", 
				"five", "six", "seven", "eight", "nine", 
				"ten"};

char str[32][64];

string calc(int n)
{
	if (n >= 100)
	{
		return hundred[n/100] + calc(n%100);
	}
	if (n >= 11)
	{
		if (n < 20)
		{
			return sp[n-10];
		}
		return ten[n/10] + calc(n%10);
	}
	return one[n];
}

int main()
{
	int n, i, j, pos, len;
	string s;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, len=0; i<n; i++)
		{
			scanf("%s", str[i]);
			if (*str[i] == '$')
			{
				pos = i;
			}
			else
			{
				for (j=0; str[i][j]; j++);
				len += j;
			}
		}
		for (i=len+1; ; i++)
		{
			s = calc(i);
			if (len+s.size() == i)
			{
				break;
			}
		}
		for (i=0; i<n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			if (i == pos)
			{
				printf("%s", s.c_str());
			}
			else
			{
				printf("%s", str[i]);
			}
		}
		puts("");
	}
	return 0;
}
