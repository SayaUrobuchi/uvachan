/*
ID: dd.ener1
PROG: snail
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

//0代表普通点，-1代表路障（包括边界），1代表走过的路径 

int S[250][250];
int N;
int res;

void input(){
	memset(S,0,sizeof(S)); 
	freopen("snail.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<=N+1;++i)
		S[i][0]=S[0][i]=S[i][N+1]=S[N+1][i]=-1;
	int b;
	scanf("%d\n",&b);
	for(int i=0;i<b;++i){
		char c;
		int d;
		scanf("%c%d\n",&c,&d);
		S[d][c-'A'+1]=-1;
	}
}
inline int max(int a,int b){
	return a>b?a:b;
}
int search3(int,int);
int search4(int,int);
int search1(int x0,int y0){//当前在(x0,y0)点，可以选择向上走
	if(S[x0-1][y0])return 0;
	int n=0,x;
	for(x=x0-1;!S[x][y0];--x,++n)
		S[x][y0]=1;
	if(S[x][y0]==-1)
		n+=max(search3(x+1,y0),search4(x+1,y0));
	for(++x;x<x0;++x)
		S[x][y0]=0;
	return n;
}
int search2(int x0,int y0){//当前在(x0,y0)点，可以选择向下走
	if(S[x0+1][y0])return 0;
	int n=0,x;
	for(x=x0+1;!S[x][y0];++x,++n)
		S[x][y0]=1;
	if(S[x][y0]==-1)
		n+=max(search3(x-1,y0),search4(x-1,y0));
	for(--x;x>x0;--x)
		S[x][y0]=0;
	return n;
}
int search3(int x0,int y0){//当前在(x0,y0)点，可以选择向左走
	if(S[x0][y0-1])return 0;
	int n=0,y;
	for(y=y0-1;!S[x0][y];--y,++n)
		S[x0][y]=1;
	if(S[x0][y]==-1)
		n+=max(search1(x0,y+1),search2(x0,y+1));
	for(++y;y<y0;++y)
		S[x0][y]=0;
	return n;
}
int search4(int x0,int y0){//当前在(x0,y0)点，可以选择向右走
	if(S[x0][y0+1])return 0;
	int n=0,y;
	for(y=y0+1;!S[x0][y];++y,++n)
		S[x0][y]=1;
	if(S[x0][y]==-1)
		n+=max(search1(x0,y-1),search2(x0,y-1));
	for(--y;y>y0;--y)
		S[x0][y]=0;
	return n;
}
void solve(){
	S[1][1]=1;
	res=max(search2(1,1),search4(1,1))+1;
}
void output(){
	freopen("snail.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	//freopen("snail.log","w",stdout);
	input();
	solve();
	output(); 
}
