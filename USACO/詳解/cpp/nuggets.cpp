/*
ID: dd.ener1
PROG: nuggets
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N;
unsigned long s[12];
unsigned long bound=2000000000;

void input(){
	freopen("nuggets.in","r",stdin);
	scanf("%d",&N);
	for(long i=0;i<N;++i)
		scanf("%d",s+i);
}
long gcd(long a,long b){
	while(b!=0){
		long r=a%b;
		a=b;
		b=r;
	}
	return a;
}
template <class T>
void update(T& old,const T& now){
	if(now<old)old=now;
}
void solve_bound(){
	for(long i=0;i<N;++i)
		for(long j=i+1;j<N;++j)
			if(gcd(s[i],s[j])==1)
				update(bound,s[i]*s[j]);
}
long all_gcd(){
	long res=s[0];
	for(long k=1;k<N;++k)
		res=gcd(res,s[k]);
	return res;
}
void solve(){
	if(bound==2000000000){
		bound=0;
		return;
	}
	bool *c=new bool[bound+1];
	memset(c,0,sizeof(bool)*(bound+1));
	for(long k=0;;++k){
		if(s[0]*k>bound)break;
		c[s[0]*k]=true;
	}
	for(long i=1;i<N;++i)
		for(long k=0;;++k){
			if(k+s[i]>bound)break;
			if(c[k])c[k+s[i]]=true;
		}
	c[0]=false;
	for(;c[bound];--bound);
}
void output(){
	freopen("nuggets.out","w",stdout);
	printf("%d\n",bound);
}
int main(){
	input();
	solve_bound();
	solve();
	output();
	return 0;
}
