#include <iostream>
#include <vector>
using namespace std;

int calc(int a, int b, const vector<int> &ary)
{
	if (ary.size() == 0)
	{
		return b + 1;
	}
	if (ary.size() == 1)
	{
		return ary.front();
	}
	return ary[1] - ary[0];
}

int main()
{
	int a, b, i;
	char buf[128];
	vector<int> va, vb;
	scanf("%d%d", &a, &b);
	for (i=a; i<=b; i++)
	{
		scanf("%s", buf);
		string s = buf;
		if (s == "Fizz")
		{
			va.emplace_back(i);
		}
		else if (s == "Buzz")
		{
			vb.emplace_back(i);
		}
		else if (s == "FizzBuzz")
		{
			va.emplace_back(i);
			vb.emplace_back(i);
		}
	}
	printf("%d %d\n", calc(a, b, va), calc(a, b, vb));
	return 0;
}
