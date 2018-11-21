/*
ID: dd.ener1
PROG: cowcycle
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
using namespace std;

int F,R;
int F1,F2,R1,R2;
int ch1[5],ch2[10];
int best1[5],best2[10];
double best;
double s[100];

void input(){
	freopen("cowcycle.in","r",stdin);
	scanf("%d%d%d%d%d%d",&F,&R,&F1,&F2,&R1,&R2);
}
inline void calc(){
	if(3*ch1[0]*ch2[0]>ch1[F-1]*ch2[R-1])return;
	int n=0;
	for(int i=F-1;i>=0;--i)
		for(int j=0;j<R;++j)
			s[n++]=double(ch1[i])/ch2[j];
	for(int i=0;i<n;++i)
		for(int j=i;j>0&&s[j-1]<s[j];--j){
			double t=s[j-1];
			s[j-1]=s[j];
			s[j]=t;
		}
	--n;
	double m=0.0;
	double v=0.0;
	for(int i=0;i<n;++i){
		s[i]-=s[i+1];
		m+=s[i];
		v+=s[i]*s[i];
	}
	m/=n;
	v=v/n-m*m;
	if(v<best){
		best=v-1e-10;
		for(int i=0;i<F;++i)
			best1[i]=ch1[i];
		for(int i=0;i<R;++i)
			best2[i]=ch2[i];
	}
}
void search2(int n,int k){
	if(n==R){
		calc();
		return;
	}
	for(int i=k;i<=R2;++i){
		ch2[n]=i;
		search2(n+1,i+1);
	}
}
void search1(int n,int k){
	if(n==F){
		search2(0,R1);
		return;
	}
	for(int i=k;i<=F2;++i){
		ch1[n]=i;
		search1(n+1,i+1);
	}
}
void solve(){
	best=1e100;
	search1(0,F1);
}
void output(){
	freopen("cowcycle.out","w",stdout);
	printf("%d",best1[0]);
	for(int i=1;i<F;++i)
		printf(" %d",best1[i]);
	printf("\n%d",best2[0]);
	for(int i=1;i<R;++i)
		printf(" %d",best2[i]);
	printf("\n");
}
int main(){
	//freopen("cowcycle.log","w",stdout);
	input();
	solve();
	output();
}
