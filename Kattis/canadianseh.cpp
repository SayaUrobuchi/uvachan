#include <iostream>
#include <cstring>
using namespace std;

const char* key = "eh?";

int main()
{
	string s;
	getline(cin, s);
	puts(strcmp(s.c_str()+s.size()-3, key)?"Imposter!":"Canadian!");
	return 0;
}