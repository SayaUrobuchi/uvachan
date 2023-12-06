#include <iostream>
using namespace std;

const string HERO_NAM[] = {
	"Shadow", "Gale", "Ranger", 
	"Anvil", "Vexia", "Guardian", 
	"Thunderheart", "Frostwhisper", "Voidclaw", 
	"Ironwood", "Zenith", "Seraphina"
};
const int CH_N = sizeof(HERO_NAM) / sizeof(HERO_NAM[0]);
const int POW[] = {
	6, 5, 4, 
	7, 3, 8, 
	6, 2, 3, 
	3, 4, 1
};
const int NONE = 0;
const int PHALANX = 1;
const int CENTERED_FOCUS = 2;
const int AB_CF_P = 5;
const int CELESTIAL_HEALING = 3;
const int AB_CH_P = 1;
const int ABL[] = {
	NONE, NONE, NONE, 
	NONE, NONE, NONE, 
	PHALANX, NONE, NONE, 
	NONE, CENTERED_FOCUS, CELESTIAL_HEALING
};
const int THUNDERHEART = 6;
const int CENTER = 1;
const int PL1 = 0;
const int PL2 = 1;
const int PL_N = 2;

int field[PL_N], level[PL_N], win[PL_N];
char nam[32];

inline int find(const char *nam)
{
	int i;
	for (i=0; i<CH_N; i++)
	{
		if (HERO_NAM[i] == nam)
		{
			return i;
		}
	}
	return -1;
}

inline int getscore(int pl)
{
	return win[pl] * 10000 + level[pl];
}

int main()
{
	int i, j, k;
	for (i=0; i<3; i++)
	{
		for (j=0; j<2; j++)
		{
			int fn, p, id;
			scanf("%d", &fn);
			int ab[4] = {};
			for (k=0, p=0; k<fn; k++)
			{
				scanf("%s", nam);
				id = find(nam);
				p += POW[id];
				++ab[ABL[id]];
			}
			p += ab[PHALANX] * POW[THUNDERHEART] * (fn == 4);
			p += ab[CENTERED_FOCUS] * AB_CF_P * (i == CENTER);
			p += ab[CELESTIAL_HEALING] * AB_CH_P * (fn - 1);
			field[j] = p;
			level[j] += p;
		}
		if (field[PL1] > field[PL2])
		{
			++win[PL1];
		}
		else if (field[PL1] < field[PL2])
		{
			++win[PL2];
		}
	}
	int pl1_score = getscore(PL1);
	int pl2_score = getscore(PL2);
	int winner = 0;
	if (pl1_score > pl2_score)
	{
		winner = 1;
	}
	else if (pl1_score < pl2_score)
	{
		winner = 2;
	}
	if (!winner)
	{
		puts("Tie");
	}
	else
	{
		printf("Player %d\n", winner);
	}
	return 0;
}
