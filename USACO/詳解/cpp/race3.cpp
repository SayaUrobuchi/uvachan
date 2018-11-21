/*
ID: dd.ener1
PROG: race3
LANG: C++
*/

#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int maxn=60;
int N;
basic_string<int> s[maxn];
basic_string<int> res1,res2;
int del;
bool vis[maxn];
bool m[maxn][maxn];
bool m2[maxn][maxn];

void input(){
	freopen("race3.in","r",stdin);
	for(N=0;;++N){
		int b;
		for(;;){
			scanf("%d",&b);
			if(b>=0)
				s[N]+=b;
			else break;
		}
		if(b==-1)break;
	}
	--N;
}
void dfs(int v){
	if(v==del)return;
	vis[v]=true;
	for(int i=s[v].size()-1;i>=0;--i)
		if(!vis[s[v][i]])dfs(s[v][i]);
}
bool conn(){
	memset(vis,0,sizeof(vis));
	dfs(0);
	return vis[N];
}
void solve1(){
	for(del=1;del<N;++del){
		if(!conn())
			res1+=del;
	}
}
bool split(int v){
	int a=0,b=0;
	for(int i=0;i<=N;++i){
		if(i==v)continue;
		if(m2[v][i])++a;
		else ++b;
	}
	if(a==0||b==0)return false;
	for(int i=0;i<=N;++i){
		if(i==v)continue;
		for(int j=0;j<=N;++j){
			if(j==v||i==j)continue;
			if(m2[v][i]&&!m2[v][j]&&(m[i][j]||m[j][i]))return false;
		}
	}
	return true;
}
void solve2(){
	memset(m,0,sizeof(m));
	memset(m2,0,sizeof(m2));
	for(int k=0;k<=N;++k)
		for(int i=s[k].size()-1;i>=0;--i)
			m[k][s[k][i]]=m2[k][s[k][i]]=true;
	for(int k=0;k<=N;++k)
		for(int i=0;i<=N;++i)
			for(int j=0;j<=N;++j)
				if(m2[i][k]&&m2[k][j])m2[i][j]=true;
	for(int i=0;i<res1.size();++i)
		if(split(res1[i]))res2+=res1[i];
}
void solve(){
	solve1();
	solve2();
}
void output(){
	freopen("race3.out","w",stdout);
	printf("%d",res1.size());
	for(int i=0;i<res1.size();++i)
		printf(" %d",res1[i]);
	putchar('\n');
	printf("%d",res2.size());
	for(int i=0;i<res2.size();++i)
		printf(" %d",res2[i]);
	putchar('\n');
}
int main(){
	input();
	solve();
	output();
}
