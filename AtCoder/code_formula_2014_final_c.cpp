#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 256;

char s[N], buf[N];
vector<string> str;

int main()
{
	int i, j;
	fgets(s, sizeof(s), stdin);
	for (i=0; s[i]; i++)
	{
		if (s[i] == '@')
		{
			int res = sscanf(s+i, "@%[a-zA-Z]", buf);
			if (res > 0)
			{
				str.emplace_back(buf);
			}
		}
	}
	sort(str.begin(), str.end());
	for (i=0; i<str.size(); i=j)
	{
		for (j=i+1; j<str.size()&&str[i]==str[j]; j++);
		puts(str[i].c_str());
	}
	return 0;
}
