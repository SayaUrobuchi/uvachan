/*
ID: dd.ener1
PROG: betsy
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=16;
int N;
bool s[maxn][maxn];
int xs[maxn];
int ys[maxn];
int nb[maxn][maxn];
int res;

void input(){
	freopen("betsy.in","r",stdin);
	scanf("%d",&N);
}
void pretreat(){
	for(int i=0;i<=N+1;++i)
		s[0][i]=s[i][0]=s[N+1][i]=s[i][N+1]=true;
	for(int i=1;i<=N;++i){
		++nb[i][1];
		++nb[1][i];
		++nb[N][i];
		++nb[i][N];
	}
	nb[N][1]=-1;
}
inline bool can(int x,int y){
	if(s[x][y])return false;
	if(xs[x+1]==N||ys[y-1]==N)return false;
	if((y==1||y==N)&&!s[x-1][y])return false;
	if(x==N&&!s[x][y+1])return false;
	if(x==1&&!s[x][y-1])return false;
	if((!(s[x-1][y]^s[x+1][y]))&&(!(s[x][y-1]^s[x][y+1]))&&(x!=1&&y!=1&&x!=N&&y!=N))return false;
	return true;
}
inline void come(int x,int y){
	s[x][y]=true;
	xs[x]++;
	ys[y]++;
	++nb[x-1][y];
	++nb[x+1][y];
	++nb[x][y-1];
	++nb[x][y+1];
}
inline void go(int x,int y){
	s[x][y]=false;
	xs[x]--;
	ys[y]--;
	--nb[x-1][y];
	--nb[x+1][y];
	--nb[x][y-1];
	--nb[x][y+1];
}
inline bool dead(int x,int y){
	return !s[x][y]&&(nb[x][y]>=3);
}
int search(int x,int y,int n){
	if(n==N*N)return 1;
	if(x==N&&y==1)return 0;
	if(dead(x-1,y)||dead(x+1,y)||dead(x,y-1)||dead(x,y+1))
		return 0;
	come(x,y);
	int dd=dead(x-1,y)+dead(x+1,y)+dead(x,y-1)+dead(x,y+1);
	int res=0;
	if(dd<=1){
		if(!dd){
			if(can(x+1,y))res+=search(x+1,y,n+1);
			if(can(x,y+1))res+=search(x,y+1,n+1);
			if(can(x-1,y))res+=search(x-1,y,n+1);
			if(can(x,y-1))res+=search(x,y-1,n+1);
		}
		else{
			if(dead(x+1,y))res=search(x+1,y,n+1);
			else if(dead(x,y+1))res=search(x,y+1,n+1);
			else if(dead(x-1,y))res=search(x-1,y,n+1);
			else if(dead(x,y-1))res=search(x,y-1,n+1);
		}
	}
	go(x,y);
	return res;
}
void solve(){
	pretreat();
	res=search(1,1,1);
}
void output(){
	freopen("betsy.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	//freopen("betsy.log","w",stdout);
	input();
	solve();
	output();
}
