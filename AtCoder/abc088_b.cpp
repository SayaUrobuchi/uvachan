#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, i, t;
	int score[2];
	priority_queue<int> pq;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		pq.emplace(t);
	}
	for (score[0]=score[1]=0, t=0; pq.size(); t=!t)
	{
		score[t] += pq.top();
		pq.pop();
	}
	printf("%d\n", score[0]-score[1]);
	return 0;
}