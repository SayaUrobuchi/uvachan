#include <iostream>
using namespace std;

const int intv[] = {
	3, 16, 34, 55, 80,
	108, 139, 172, 208, 245, 
	285, 327, 9999
};
const string nam[] = {
	"Logn", "Andvari", "Kul", "Gola", "Stinningsgola", 
	"Kaldi", "Stinningskaldi", "Allhvass vindur", "Hvassvidri", "Stormur", 
	"Rok", "Ofsavedur", "Farvidri"
};

int main()
{
	int a, b, i;
	char c;
	cin >> a >> c >> b;
	int n = a * 10 + b;
	for (i=0; i<13&&n>=intv[i]; i++);
	cout << nam[i] << "\n";
	return 0;
}
