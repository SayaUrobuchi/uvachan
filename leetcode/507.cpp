#include <math.h>

int tbl[10005], prime[10005], pn;

bool checkPerfectNumber(int num) {
	int i, res, sq;
	if (num == 1)
	{
		return false;
	}
    res = 1;
    sq = sqrt(num)+1;
    for (i=2; i<sq; i++)
    {
    	if (!(num % i))
    	{
    		res += i;
    		if (i*i != num)
    		{
    			res += num/i;
    		}
    	}
    }
    return res == num;
}
