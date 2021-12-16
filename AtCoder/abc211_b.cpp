#include <iostream>
#include <cstring>
using namespace std;

const char *key[] = {"H", "2B", "3B", "HR"};

char s[4][8];

int main()
{
	int i, j;
	bool gg, found;
	while (scanf("%s%s%s%s", s[0], s[1], s[2], s[3]) == 4)
	{
		for (i=0, gg=false; i<4&&!gg; i++)
		{
			for (j=0, found=false; j<4&&!found; j++)
			{
				if (strcmp(key[i], s[j]) == 0)
				{
					found = true;
				}
			}
			if (!found)
			{
				gg = true;
			}
		}
		puts(gg?"No":"Yes");
	}
	return 0;
}
