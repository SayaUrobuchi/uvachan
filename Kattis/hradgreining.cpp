#include <iostream>
using namespace std;

const string COV = "COV";

char buf[1005];

int main()
{
	int i, j;
	scanf("%s", buf);
	string s = buf;
	bool is_appr = false;
	for (i=0; !is_appr&&i+COV.size()<=s.size(); i++)
	{
		bool ok = true;
		for (j=0; ok&&j<COV.size(); j++)
		{
			if (s[i+j] != COV[j])
			{
				ok = false;
			}
		}
		is_appr = ok;
	}
	puts(is_appr?"Veikur!":"Ekki veikur!");
	return 0;
}
