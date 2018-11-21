#include <string>

using namespace std;

class BlackWhiteMagic
{
public:
	int count(string s)
	{
		int i, b, w;
		for(i=0, w=0; i<s.size(); i++)
		{
			if(s[i] == 'W')
			{
				w++;
			}
		}
		for(i=0, b=0; i<w; i++)
		{
			if(s[i] == 'B')
			{
				b++;
			}
		}
		return b;
	}
};
