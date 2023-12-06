#include <iostream>
#include <cstring>
using namespace std;

const int R = 0;
const int A = 1;
const char *NAM[] = {"Reykjavik", "Kopavogur", "Hafnarfjordur", "Reykjanesbaer", 
					 "Akureyri", "Gardabaer", "Mosfellsbaer", "Arborg", 
					 "Akranes", "Fjardabyggd", "Mulathing", "Seltjarnarnes"};
const int N = sizeof(NAM) / sizeof(NAM[0]);
const int SIT[] = {R, R, R, R, A, R, R, R, R, A, A, R};
const char *CNAM[] = {"Reykjavik", "Akureyri"};

char s[32];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; i<N; i++)
	{
		if (!strcmp(s, NAM[i]))
		{
			puts(CNAM[SIT[i]]);
			break;
		}
	}
	return 0;
}
