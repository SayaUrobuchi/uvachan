#include <stdio.h>
#include <string>

char s[10000005];
std::string str[100000];

int main()
{
	int i, ptr, tail;
	while(gets(s))
	{
		str[0].clear();
		tail = 1;
		ptr = 0;
		for(i=0; s[i]; i++)
		{
			if(s[i] == '[')
			{
				ptr = tail++;
				str[ptr] = "";
			}
			else if(s[i] == ']')
			{
				ptr = 0;
			}
			else
			{
				str[ptr] += s[i];
			}
		}
		for(i=tail-1; i>=0; i--)
		{
			printf("%s", str[i].c_str());
		}
		printf("\n");
	}
	return 0;
}
