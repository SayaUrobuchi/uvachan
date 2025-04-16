#include <iostream>
using namespace std;

char buf[105];

int main()
{
	int i, j;
	scanf("%s", buf);
	string s = buf;
	int ans = 0;
	for (i=0; i<s.size(); i++)
	{
		if (s[i] == 'A')
		{
			for (j=1; i+j+j<s.size(); j++)
			{
				if (s[i+j] == 'B' && s[i+j+j] == 'C')
				{
					++ans;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
