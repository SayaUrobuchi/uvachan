#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string key[] = {"---+", "  /|", " / |", "/  |"};

int main()
{
	int a, b, i, j, k, l;
	string s0, s1, s2, top, temp, inner[4], t;
	while (cin >> s0 >> s1)
	{
		if (s0 == "0" && s1 == "0")
		{
			break;
		}
		sscanf(s0.c_str(), "%d", &a);
		sscanf(s1.c_str(), "%d", &b);
		stringstream ss;
		ss << a*b;
		s2 = ss.str();
		reverse(s2.begin(), s2.end());
		top = "+";
		top.resize(1+(3+(s0.size()<<2)), '-');
		top += '+';
		temp.clear();
		temp.resize(top.size(), ' ');
		temp[0] = temp[temp.size()-1] = '|';
		for (j=0; j<4; j++)
		{
			inner[j] = "| ";
			inner[j] += key[j].back();
			for (i=0; i<s0.size(); i++)
			{
				inner[j] += key[j];
			}
			inner[j] += " |";
		}
		
		cout << top << "\n";
		t = temp;
		for (i=4, j=0; j<s0.size(); j++, i+=4)
		{
			t[i] = s0[j];
		}
		cout << t << "\n";
		cout << inner[0] << "\n";
		for (i=0, k=s0.size()+s1.size()-1; i<s1.size(); i++, k--)
		{
			t = inner[1];
			if (k+1 < s2.size())
			{
				t[1] = '/';
			}
			for (j=3, l=0; l<s0.size(); l++, j+=4)
			{
				t[j] = (s0[l]-'0') * (s1[i]-'0') / 10 + '0';
			}
			cout << t << "\n";
			t = inner[2];
			t[t.size()-2] = s1[i];
			cout << t << "\n";
			t = inner[3];
			if (k < s2.size())
			{
				t[1] = s2[k];
			}
			for (j=5, l=0; l<s0.size(); l++, j+=4)
			{
				t[j] = (s0[l]-'0') * (s1[i]-'0') % 10 + '0';
			}
			cout << t << "\n";
			cout << inner[0] << "\n";
		}
		t = temp;
		for (i=1; k>=0; i+=4, k--)
		{
			if (k+1 < s2.size())
			{
				t[i] = '/';
			}
			if (k < s2.size())
			{
				t[i+2] = s2[k];
			}
		}
		cout << t << "\n";
		cout << top << "\n";
	}
	return 0;
}
