#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

string code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
"...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----"};
string chara = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
int id[128];
unordered_map<string, char> tbl;

int main()
{
	int i, j, k;
	string s, t, u;
	for (i=0; i<chara.size(); i++)
	{
		tbl[code[i]] = chara[i];
		//cout << code[i] << ": " << chara[i] << "\n";
		id[chara[i]] = i;
	}
	while (getline(cin, s))
	{
		t = "";
		u = "";
		for (i=0; i<s.size(); i++)
		{
			t += code[id[s[i]]];
			u += (char)(code[id[s[i]]].size()+'0');
		}
		reverse(u.begin(), u.end());
		s = "";
		for (i=0, j=0; i<u.size(); i++)
		{
			k = u[i] - '0';
			s += tbl[t.substr(j, k)];
			j += k;
		}
		cout << s << "\n";
	}
	return 0;
}
