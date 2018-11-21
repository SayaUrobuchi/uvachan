/*
ID: dd.ener1
PROG: humble
LANG: C++
*/
#include <cstdio>
using namespace std;

long N,K,s[100];
unsigned long ham[1000000];
long dex[100];
const unsigned long OO=~0;

void input(){
	freopen("humble.in","r",stdin);
	scanf("%d%d",&N,&K);
	for(long i=0;i<N;++i)scanf("%d",s+i);
}
inline void solve(){
	ham[0]=1;
	for(long k=1;k<=K;++k){
		unsigned long min=OO;
		for(long i=0;i<N;++i)
			for(long j=dex[i];j<k;++j){
				unsigned long now=s[i]*ham[j];
				if(now>ham[k-1]){
					if(now<min)min=now;
					dex[i]=j;
					break;
				}
			}
		ham[k]=min;
	}
}
void output(){
	freopen("humble.out","w",stdout);
	printf("%d\n",ham[K]);
}
int main(){
	input();
	solve();
	output();
}
