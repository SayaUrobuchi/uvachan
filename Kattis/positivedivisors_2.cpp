#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using pp = pair<long long, int>;

int main()
{
    int i;
    long long n;
    vector<long long> rev;
    scanf("%lld", &n);
    for (i=1; (long long)i*i<=n; i++)
    {
        if (n % i == 0)
        {
        	printf("%d\n", i);
        	if (i*i != n)
        	{
        		rev.emplace_back(n/i);
        	}
        }
    }
    while (rev.size())
    {
    	printf("%lld\n", rev.back());
    	rev.pop_back();
    }
    return 0;
}