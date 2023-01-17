#include <iostream>
using namespace std;

const int N = 128;
const int M = 512;

char key[M], buf[M];
char avail[128];
string str[N];

int main()
{
	int i, j, p;
	bool gg;
	scanf("%s", key);
	p = 0;
	gg = false;
	for (i='a', j=0; i<='z'; i++, j++)
	{
		avail[j] = i;
	}
	for (i='0'; i<='9'; i++, j++)
	{
		avail[j] = i;
	}
	while (scanf("%s", buf) == 1)
	{
		if (!gg)
		{
			char c = key[p];
			if (!c)
			{
				gg = true;
				continue;
			}
			if (str[c].empty())
			{
				for (i=0; avail[i]; i++)
				{
					if (str[avail[i]] == buf)
					{
						break;
					}
				}
				if (avail[i])
				{
					gg = true;
				}
				else
				{
					str[c] = buf;
				}
			}
			else if (str[c] != buf)
			{
				gg = true;
			}
			++p;
		}
	}
	if (!gg && key[p])
	{
		gg = true;
	}
	puts(gg?"False":"True");
	return 0;
}
