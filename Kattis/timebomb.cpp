#include <iostream>
using namespace std;

string tbl[] = {"***   * *** *** * * *** *** *** *** ***", 
				"* *   *   *   * * * *   *     * * * * *",
				"* *   * *** *** *** *** ***   * *** ***",
				"* *   * *     *   *   * * *   * * *   *",
				"***   * *** ***   * *** ***   * *** ***"};
string s[8];

int judge(int c)
{
	int i, j, k;
	for (i=0, j=0; i<=9; i++, j+=4)
	{
		for (k=0; k<5; k++)
		{
			if (s[k][c] != tbl[k][j] || s[k][c+1] != tbl[k][j+1] || s[k][c+2] != tbl[k][j+2])
			{
				break;
			}
		}
		if (k >= 5)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int i, t, ans;
	while (getline(cin, s[0]))
	{
		for (i=1; i<5; i++)
		{
			getline(cin, s[i]);
		}
		for (i=0, ans=0; i<s[0].size(); i+=4)
		{
			t = judge(i);
			if (t < 0)
			{
				ans = 1;
				break;
			}
			ans = ans*10 + t;
		}
		if (ans % 6 == 0)
		{
			puts("BEER!!");
		}
		else
		{
			puts("BOOM!!");
		}
	}
	return 0;
}
