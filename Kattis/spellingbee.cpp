#include<iostream>
using namespace std;

int tbl[128];
char s[1024];

int main()
{
	int n, i, j, ucnt;
	char c;
	bool mid;
	ucnt = 0;
	while (scanf("%s%d", s, &n) == 2)
	{
		++ucnt;
		for (i=0; s[i]; i++)
		{
			tbl[s[i]] = ucnt;
		}
		c = s[0];
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0, mid=false; s[j]; j++)
			{
				if (tbl[s[j]] != ucnt)
				{
					break;
				}
				if (s[j] == c)
				{
					mid = true;
				}
			}
			if (j >= 4 && mid && !s[j])
			{
				//printf("lagsgjslga;jala    ");
				puts(s);
			}
		}
	}
	return 0;
}
