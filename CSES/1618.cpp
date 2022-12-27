#include <iostream>
using namespace std;

int main()
{
	int n;
	long long ans;
	while (cin >> n)
	{
		for (ans=0; n>=5; ans+=n/=5);
		cout << ans << "\n";
	}
	return 0;
}

