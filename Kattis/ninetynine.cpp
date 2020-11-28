#include <iostream>
using namespace std;

const int LOSE = 0;
const int WIN = 1;

int dp[128];

int main()
{
	int i;
	dp[99] = LOSE;
	dp[100] = WIN;
	for (i=98; i>=1; i--)
	{
		if (dp[i+1] == WIN && dp[i+2] == WIN)
		{
			dp[i] = LOSE;
		}
		else
		{
			dp[i] = WIN;
		}
		//cout << i << ": " << (dp[i] == LOSE ? "LOSE" : "WIN") << "\n";
	}
	cout << (dp[1] == WIN ? 1 : 2) << endl;
	while (cin >> i)
	{
		if (i == 99)
		{
			break;
		}
		if (dp[i+1] == LOSE)
		{
			cout << i+1 << endl;
			if (i+1 == 99)
			{
				break;
			}
		}
		else
		{
			cout << i+2 << endl;
			if (i+2 == 99)
			{
				break;
			}
		}
	}
	return 0;
}
