#include <iostream>
using namespace std;

int cnt[16];

int calc(int t)
{
	int res;
	for (res=0; t; t/=10, res++)
	{
		cnt[t%10]++;
	}
	return res;
}

int main()
{
	int count, i, j, st, ed, diff, n, total;
	string nam, s;
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, nam);
		getline(cin, s);
		cout << nam << "\n";
		cout << s << "\n";
		sscanf(s.c_str(), "%d", &n);
		for (i=0; i<10; i++)
		{
			cnt[i] = 0;
		}
		for (total=0; n; )
		{
			getline(cin, s);
			if (s[0] == '+')
			{
				sscanf(s.c_str()+1, "%d%d%d", &st, &ed, &diff);
				for (j=st; j<=ed; j+=diff, n--)
				{
					total += calc(j);
				}
			}
			else
			{
				sscanf(s.c_str(), "%d", &st);
				total += calc(st);
				n--;
			}
		}
		for (i=0; i<10; i++)
		{
			cout << "Make " << cnt[i] << " digit " << i << "\n"; 
		}
		cout << "In total " << total << " digit" << (total==1?"":"s") << "\n";
	}
	return 0;
}
