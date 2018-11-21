#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
	Solution()
	{
		dp.resize(1000);
		count.resize(1000);
	}
	vector<unordered_map<int, int> > dp, count;
    int numberOfArithmeticSlices(vector<int>& A) {
		int i, j, t, ans, gap;
		long long tt;
	    unordered_map<int, int>::iterator it;
		ans = 0;
	    for (i=1; i<A.size(); i++)
	    {
	    	dp[i].clear();
	    	count[i].clear();
	    	for (j=0; j<i; j++)
	    	{
	    		tt = (long long)A[i] - A[j];
	    		if (tt >= -2147483648LL && tt <= 2147483647)
	    		{
	    			gap = (int)tt;
		    		t = 0;
		    		if ((it=dp[j].find(gap)) != dp[j].end())
		    		{
		    			t += it->second;
		    		}
		    		if ((it=count[j].find(gap)) != count[j].end())
		    		{
		    			t += it->second;
		    		}
	    			count[i][gap]++;
	    			if (t)
	    			{
		    			dp[i][gap] += t;
			    		ans += t;
			    	}
			    }
	    	}
	    }
	    return ans;
        
    }
};

