/*
ID: dd.ener1
PROG: heritage
LANG: C++
*/
#include <cstdio>
using namespace std;

long N;
char mid[30];
char pre[30];

void input(){
	N=0;
	freopen("heritage.in","r",stdin);
	for(;;){
		char c=getchar();
		if(c=='\n')break;
		mid[N++]=c;
	}
	for(long i=0;i<N;++i)
		pre[i]=getchar();
}
inline void output(char c){
	putchar(c);
}
void solve(long midbeg,long prebeg,long len){
	if(len==0)return;
	long k;
	for(k=0;mid[k+midbeg]!=pre[prebeg];++k);
	solve(midbeg,prebeg+1,k);
	solve(midbeg+k+1,prebeg+k+1,len-k-1);
	output(mid[midbeg+k]);
}
int main(){
	freopen("heritage.out","w",stdout);
	input();
	solve(0,0,N);
	output('\n');
	return 0;
}
