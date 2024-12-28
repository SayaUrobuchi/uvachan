#include <iostream>
using namespace std;

const string NAM[] = {
	"tourist",
	"ksun48",
	"Benq",
	"Um_nik",
	"apiad",
	"Stonefeang",
	"ecnerwala",
	"mnbvmar",
	"newbiedmy",
	"semiexp"
};
const int SCORE[] = {
	3858, 3679, 3658, 3648, 3638, 
	3630, 3613, 3555, 3516, 3481
};
const int N = 32;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int ans;
	for (i=0; i<10; i++)
	{
		if (NAM[i] == s)
		{
			ans = SCORE[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
