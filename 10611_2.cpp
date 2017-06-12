#include <iostream>

using namespace std;

int height, j;
int ary[50001];

int bisearch()
{
	int left, right, center;
	left = 0;
	right = j;
	for(center=(left+right)/2; ; center=(left+right)/2)
	{
		if(ary[center] < height)
		{
			left = center + 1;
			if(left > right)
			{
				return center;
			}
		}
		else
		{
			right = center - 1;
			if(left > right)
			{
				return right;
			}
		}
	}
}

int main()
{
	int n, m, i, index;
	cin >> n >> ary[0];
	for(i=1, j=0; i<n; i++)
	{
		cin >> height;
		if(height > ary[j])
		{
			ary[++j] = height;
		}
	}
	cin >> m;
	while(m--)
	{
		cin >> height;
		index = bisearch();
		if(index == -1)
		{
			cout << 'X';
		}
		else
		{
			cout << ary[index];
		}
		index++;
		if(ary[index] == height)
		{
			index++;
		}
		if(index > j)
		{
			cout << " X\n";
		}
		else
		{
			cout << ary[index] << '\n';
		}
	}
	/*scanf(" ");*/
	return 0;
}
