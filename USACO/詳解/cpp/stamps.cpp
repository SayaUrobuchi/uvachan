/*
ID: dd.ener1
PROG: stamps
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N,K;
long v[100];
unsigned long s[2001000];

void input(){
	freopen("stamps.in","r",stdin);
	long n;
	scanf("%d%d",&K,&n);
	do{
		scanf("%d",v+N);
		bool uni=true;
		for(long i=0;i<N;++i)
			if(v[i]==v[N]){
				uni=false;
				break;
			}
		if(uni)++N;
	}while(--n);
}
template <class T>
inline void update(T& old,const T& updater){
	if(old>updater)old=updater;
}
long solve(){
	long maxs=-1;
	for(long i=0;i<N;++i)if(v[i]>maxs)maxs=v[i];
	maxs*=K;
	memset(s,-1,sizeof(s));
	s[0]=0;
	for(long i=1;i<=maxs;++i)
		for(long j=0;j<N;++j){
			if(i<v[j])continue;
			update(s[i],s[i-v[j]]+1);
		}
	long res=-1;
	long now=0;
	for(long i=1;i<=maxs;++i){
		if(s[i]>K)now=0;
		else{
			++now;
			if(now>res)res=now;
		}
	}
	return res;
}
void output(long res){
	freopen("stamps.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	output(solve());
}
