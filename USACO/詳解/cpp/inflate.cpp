/*
ID: dd.ener1
PROG: inflate
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxn=10010;
long M,N;
long v[maxn];
long t[maxn];
long best[maxn];

void input(){
	freopen("inflate.in","r",stdin);
	scanf("%d%d",&M,&N);
	for(long i=0;i<N;++i)
		scanf("%d%d",v+i,t+i);
	memset(best,0,sizeof(best));
}
inline void update(long& old,const long& updater){
	if(updater>old)old=updater;
}
void solve(){
	for(long k=0;k<N;++k)
		for(long i=0;;++i){
			if(i+t[k]>M)break;
			update(best[i+t[k]],best[i]+v[k]);
		}
}
void output(){
	long max=-1;
	for(long i=0;i<=M;++i)
		update(max,best[i]);
	freopen("inflate.out","w",stdout);
	printf("%d\n",max);
}
int main(){
	input();
	solve();
	output();
}
