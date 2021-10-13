#include <iostream>
using namespace std;

int ary[1024], bry[1024];

bool aa(int ary[])
{
	return (ary[1]^ary[3]) && !(ary[1]^ary[5]);
}

bool bb(int ary[], int bry[])
{
	return ary[6] == 1 && bry[6] == 0;
}

bool cc(int ary[], int bry[])
{
	return (ary[1]^bry[1]) && (ary[3]^bry[3]) && (ary[5]^bry[5]);
}

int main()
{
	int n, i, j;
	bool flag;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<7; j++)
			{
				cin >> ary[j];
			}
			for (j=0; j<7; j++)
			{
				cin >> bry[j];
			}
			flag = false;
			if (!aa(ary) || !aa(bry))
			{
				cout << 'A';
				flag = true;
			}
			if (!bb(ary, bry))
			{
				cout << 'B';
				flag = true;
			}
			if (!cc(ary, bry))
			{
				cout << 'C';
				flag = true;
			}
			if (!flag)
			{
				cout << "None";
			}
			cout << "\n";
		}
	}
	return 0;
}
