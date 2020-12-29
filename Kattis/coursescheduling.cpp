#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

using mm = map<string, int>;

char fn[1024], sn[1024], cn[1024], buf[1024];

int main()
{
	int n, i;
	unordered_map<string, int> nam;
	mm cls;
	while (scanf("%d", &n) == 1)
	{
		nam.clear();
		cls.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s%s%s", fn, sn, cn);
			sprintf(buf, "%s:%s:%s", fn, sn, cn);
			if (!(nam[buf]++))
			{
				++cls[cn];
			}
		}
		for (mm::iterator it=cls.begin(); it!=cls.end(); ++it)
		{
			printf("%s %d\n", (it->first).c_str(), it->second);
		}
	}
	return 0;
}
