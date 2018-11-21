#include <string>
#include <cstring>

using namespace std;

int ht[55][130005];

class KindAndCruel
{
public:
	int qq[400005], qs[400005];
	
	int crossTheField(string s, int k, int c)
	{
		int n, i, j, l, loc, step;
		
		memset(ht, 0, sizeof(ht));
		n = s.size();
		qq[0] = 0;
		qs[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			if(i > 320000)
			{
				j = 0;
				break;
			}
			if(j > 320000)
			{
				j = 320000;
			}
			loc = qq[i];
			step = qs[i];
			if(loc == n-1)
			{
				break;
			}
			if(step > 130000)
			{
				continue;
			}
			for(l=loc-1; l<=loc+1; l++)
			{
				if(l < 0)
				{
					continue;
				}
				if(ht[l][step+1] == 0 && (s[l] == '.' || (s[l] == 'C' && (step+1) % c == 0) || (s[l] == 'K' && (step+1) % k)))
				{
					qq[j] = l;
					qs[j] = step+1;
					ht[l][step+1] = 1;
					j++;
				}
			}
		}
		if(i < j)
		{
			return step;
		}
		return -1;
	}
};
