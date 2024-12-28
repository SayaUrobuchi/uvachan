#include <iostream>
using namespace std;

bool mom[128];

int main()
{
	mom['a'] = mom['e'] = mom['i'] = mom['o'] = mom['u'] = true;
	char c;
	scanf("%c", &c);
	puts(mom[c] ? "vowel" : "consonant");
	return 0;
}
