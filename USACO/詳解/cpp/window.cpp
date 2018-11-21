/*
ID: dd.ener1
PROG: window
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=256;

int head,tail;
int prev[maxn];
int next[maxn];

inline void addhead(int x){
	prev[x]=-1;
	next[x]=head;
	if(head!=-1)prev[head]=x;
	head=x;
	if(tail==-1)tail=x;
}
inline void addtail(int x){
	next[x]=-1;
	prev[x]=tail;
	if(tail!=-1)next[tail]=x;
	tail=x;
	if(head==-1)head=x;
}
inline void remove(int x){
	if(x!=tail)prev[next[x]]=prev[x];
	if(x!=head)next[prev[x]]=next[x];
	if(x==tail)tail=prev[x];
	if(x==head)head=next[x];
}

char s[maxn];
int L[maxn],R[maxn],U[maxn],D[maxn];

inline void swap(int& a,int& b){
	int t=a;
	a=b;
	b=t;
}
inline int get_n(){
	return s[2]; 
}
int cut(int l,int r,int u,int d,int k){
	while(k!=-1&&(R[k]<=l||L[k]>=r||U[k]>=d||D[k]<=u))k=next[k];
	if(k==-1)return (r-l)*(d-u);
	int res=0;
	if(L[k]>l){
		res+=cut(l,L[k],u,d,next[k]);
		l=L[k];
	}
	if(R[k]<r){
		res+=cut(R[k],r,u,d,next[k]);
		r=R[k];
	}
	if(U[k]>u)
		res+=cut(l,r,u,U[k],next[k]);
	if(D[k]<d)
		res+=cut(l,r,D[k],d,next[k]);
	return res;
}

inline void solve_w(){
	int n=get_n();
	sscanf(s+4,"%d,%d,%d,%d",L+n,U+n,R+n,D+n);
	if(R[n]<L[n])swap(R[n],L[n]);
	if(D[n]<U[n])swap(U[n],D[n]);
	addtail(n);
}
inline void solve_t(){
	int n=get_n();
	remove(n);
	addtail(n);
}
inline void solve_b(){
	int n=get_n();
	remove(n);
	addhead(n);
}
inline void solve_d(){
	int n=get_n();
	remove(n);
}
inline void solve_s(){
	int n=get_n();
	int m=cut(L[n],R[n],U[n],D[n],next[n]);
	printf("%.3lf\n",100.0*(double)m/((R[n]-L[n])*(D[n]-U[n])));
}

inline void solve(){
	switch(s[0]){
		case 'w':
			solve_w();
			break;
		case 't':
			solve_t();
			break;
		case 'b':
			solve_b();
			break;
		case 'd':
			solve_d();
			break;
		case 's':
			solve_s();
	}
}

int main(){
	head=tail=-1;
	memset(prev,-1,sizeof(prev));
	memset(next,-1,sizeof(next));

	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	
	do{
		scanf("%s\n",s);
		solve();
	}while(!feof(stdin));
}
