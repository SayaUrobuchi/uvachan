#include <iostream>
using namespace std;

const string KEY = "oxx";

char buf[16];

int main()
{
	int i, j;
	scanf("%s", buf);
	bool found = false;
	for (j=0; j<3&&!found; j++)
	{
		for (i=0; buf[i]; i++)
		{
			if (buf[i] != KEY[(i+j)%3])
			{
				break;
			}
		}
		if (!buf[i])
		{
			found = true;
		}
	}
	puts(found ? "Yes" : "No");
	return 0;
}
