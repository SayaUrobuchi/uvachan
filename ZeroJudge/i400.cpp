#include <iostream>
using namespace std;

char buf[256];
string e[105];

int main()
{
	int en, len, i, j, sum, l, r, head, tail;
	string t;
	// read data
	cin >> en >> len;
	for (i=0; i<en; i++)
	{
		cin >> e[i];
	}
	cin >> t;
	// process data
	//   for every e calc the string before encode
	for (i=en-1; i>=0; i--)
	{
		//     calc the string before step 2
		head = 120;
		tail = head;
		for (j=len-1; j>=0; j--)
		{
			if (e[i][j] == '0')
			{
				head--;
				buf[head] = t[j];
			}
			else
			{
				buf[tail] = t[j];
				tail++;
			}
		}
		t = "";
		for (j=head; j<tail; j++)
		{
			t += buf[j];
		}
		//     calc the string before step 1
		for (j=0, sum=0; j<len; j++)
		{
			if (e[i][j] == '1')
			{
				sum++;
			}
		}
		if (sum % 2 != 0)
		{
			for (l=0, r=(len+1)/2; l<len/2; l++, r++)
			{
				swap(t[l], t[r]);
			}
		}
		//cout << t << "\n";
	}
	// print answer
	cout << t << "\n";
	return 0;
}