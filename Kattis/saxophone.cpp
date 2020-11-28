#include <iostream>
#include <cstring>

const char *key = "cdefgabCDEFGAB";
const char *buf;
int ff[16], ans[16];
int tbl[128];
int fing[][11] = {
	// 0  1  2  3  4  5  6  7  8  9 10
	{  0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1  }, 
	{  0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0  }, 
	{  0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0  }, 
	{  0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0  }, 
	{  0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0  }, 
	{  0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0  }, 
	{  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0  }, 
	// 0  1  2  3  4  5  6  7  8  9 10
	{  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0  }, 
	{  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0  }, 
	{  0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0  }, 
	{  0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0  }, 
	{  0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0  }, 
	{  0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0  }, 
	{  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0  }, 
	// 0  1  2  3  4  5  6  7  8  9 10
};

int main()
{
	int count, i, j, t;
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = i;
	}
	scanf("%d", &count);
	std::string s;
	std::getline(std::cin, s);
	while (count--)
	{
		std::getline(std::cin, s);
		buf = s.c_str();
		memset(ff, 0, sizeof(ff));
		memset(ans, 0, sizeof(ans));
		for (i=0; i<s.size(); i++)
		{
			t = tbl[buf[i]];
			for (j=1; j<=10; j++)
			{
				if (!ff[j] && fing[t][j])
				{
					++ans[j];
				}
				ff[j] = fing[t][j];
			}
		}
		printf("%d", ans[1]);
		for (i=2; i<=10; i++)
		{
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}