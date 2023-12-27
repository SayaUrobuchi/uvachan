#include "countingdays.h"

static int d = 1;
static int t = 0;

void lookAtClock(int hours, int minutes) {
	int nxt = hours * 60 + minutes;
	if (nxt < t)
	{
		++d;
	}
	t = nxt;
}

int getDay() {
    return d;
}