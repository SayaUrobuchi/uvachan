/*
ID: dd.ener1
PROG: tour
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn=128;
int N;
bool g[maxn][maxn];
string s[maxn];
int v[128][128];
int res;

int find(const string& S){
	for(int i=0;i<N;++i)
		if(S==s[i])return i;
	return -1;
}
void input(){
	freopen("tour.in","r",stdin);
	int m;
	cin>>N>>m;
	for(int i=0;i<N;++i)
		cin>>s[i];
	for(int i=0;i<m;++i){
		string a,b;
		cin>>a>>b;
		int i=find(a),j=find(b);
		g[i][j]=g[j][i]=true;
	}
}
inline bool update(int& old,int x){
	if(x>old){
		old=x;
		return true;
	}
	return false;
}
void solve(int i,int j){//i<j
	for(int k=j;k<N;++k){
		if(g[i][k])
			if(update(v[j][k],v[i][j]+1))
				if(j!=k)solve(j,k);
		if(g[j][k])
			if(update(v[i][k],v[i][j]+1))
				if(i!=k)solve(i,k);
	}
}
void solve(){
	memset(v,-1,sizeof(v));
	v[0][0]=1;
	solve(0,0);
	res=1;
	update(res,v[N-1][N-1]-1);
}
void output(){
	freopen("tour.out","w",stdout);
	cout<<res<<endl;
}
int main(){
	freopen("tour.log","w",stdout);
	input();
	solve();
	output();
}
