#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 19;
const int M = 10000;
//                 01234567890123456789
const char *key = " welcome to code jam";

int dp[32];

int main()
{
	int count, cas, i, j;
	string s;
	cas = 0;
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i=0; i<s.size(); i++)
		{
			for (j=N; j>0; j--)
			{
				if (s[i] == key[j])
				{
					dp[j] = (dp[j]+dp[j-1]) % M;
					//cout << "(" << i << ", " << j << ")\n";
				}
			}
		}
		cout << "Case #" << ++cas << ": " << setw(4) << setfill('0') << dp[N] << "\n";
	}
	return 0;
}
