/*
ID: dd.ener1
PROG: starry
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

struct item{
	int Left,Top,Down,Right;
	int Num;
	item():Left(1000),Top(1000),Down(-1),Right(-1),Num(0){}
}M[600];
int N;
int H,W;
char s[200][200];
int S[200][200];
int S2[200][200];
int V[600];
char C[600];

void input(){
	freopen("starry.in","r",stdin);
	scanf("%d%d\n",&W,&H);
	for(int i=0;i<H;++i)
		scanf("%s\n",s[i]);
}
void flood(int i,int j,int n){
	if(i<0||j<0||i>=H||j>=W)return;
	if(s[i][j]=='0')return;
	s[i][j]='0';
	S[i][j]=n;
	flood(i-1,j-1,n);
	flood(i,j-1,n);
	flood(i-1,j,n);
	flood(i+1,j+1,n);
	flood(i,j+1,n);
	flood(i+1,j,n);
	flood(i-1,j+1,n);
	flood(i+1,j-1,n);
}
void pretreat(){
	memset(S,-1,sizeof(S));
	for(int i=0;i<H;++i)
	    for(int j=0;j<W;++j)
	        if(s[i][j]=='1')flood(i,j,N++);
	for(int i=0;i<H;++i)
	    for(int j=0;j<W;++j){
			if(-1==S[i][j])continue;
			item& now=M[S[i][j]];
			now.Num++;
			if(i<now.Top)now.Top=i;
			if(i>now.Down)now.Down=i;
			if(j<now.Left)now.Left=j;
			if(j>now.Right)now.Right=j;
		}
}
bool maybe(int i,int j){
	if(M[i].Num!=M[j].Num)return false;
	if(M[i].Left-M[i].Right==M[j].Left-M[j].Right&&M[i].Top-M[i].Down==M[j].Top-M[j].Down)return true;
	if(M[i].Left-M[i].Right==M[j].Top-M[j].Down&&M[i].Top-M[i].Down==M[j].Left-M[j].Right)return true;
	return false;
}
void turn0(int Left,int Right,int Top,int Down){//不翻转
	for(int i=Top;i<=Down;++i)
		for(int j=Left;j<=Right;++j)
			S2[i][j]=S[i][j];
}
void turn1(int Left,int Right,int Top,int Down){//左右对称翻转
	for(int i=0;i<=Right-Left;++i) 
		for(int k=Top;k<=Down;++k)
			S2[k][Right-i]=S[k][Left+i];
}
void turn2(int Left,int Right,int Top,int Down){//左右对称翻转 
	for(int i=0;i<=Down-Top;++i)
		for(int k=Left;k<=Right;++k)
			S2[Down-i][k]=S[Top+i][k];
}
void turn3(int Left,int Right,int Top,int Down){//中心对称翻转
	for(int i=0;i<=Right-Left;++i)
		for(int j=0;j<=Down-Top;++j)
			S2[Down-j][Right-i]=S[Top+j][Left+i];
}
bool exact1(int a,int b){
	for(int i=0;i<=M[a].Down-M[a].Top;++i)
		for(int j=0;j<=M[a].Right-M[a].Left;++j)
			if((a==S2[M[a].Top+i][M[a].Left+j])^(b==S[M[b].Top+i][M[b].Left+j]))
				return false;
	return true;
}
bool exact2(int a,int b){
	for(int i=0;i<=M[a].Down-M[a].Top;++i)
		for(int j=0;j<=M[a].Right-M[a].Left;++j)
			if((a==S2[M[a].Top+i][M[a].Left+j])^(b==S[M[b].Top+j][M[b].Left+i]))
				return false;
	return true;
}
bool exact(int i,int j){
	if(M[i].Left-M[i].Right==M[j].Left-M[j].Right){
		turn0(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact1(i,j))return true;
		turn1(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact1(i,j))return true;
		turn2(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact1(i,j))return true;
		turn3(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact1(i,j))return true;
	}
	if(M[i].Left-M[i].Right==M[j].Top-M[j].Down){
		turn0(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact2(i,j))return true;
		turn1(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact2(i,j))return true;
		turn2(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact2(i,j))return true;
		turn3(M[i].Left,M[i].Right,M[i].Top,M[i].Down);
		if(exact2(i,j))return true;
	}
	return false;
}
void solve(){
	pretreat();
	for(int i=0;i<N;++i)
		V[i]=i;
	char c='a';
	for(int i=0;i<N;++i){
		if(V[i]!=i){
			C[i]=C[V[i]];
			continue;
		}
		C[i]=c++;
		for(int j=i+1;j<N;++j){
			if(V[j]!=j)continue;
			if(!maybe(i,j))continue;
			if(exact(i,j))
				V[j]=i;
		}
	}
}
void output(){
	freopen("starry.out","w",stdout);
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(S[i][j]==-1)
				putchar('0');
			else
				putchar(C[S[i][j]]);
		}
		putchar('\n');
	}
}
int main(){
	//freopen("starry.log","w",stdout);
	input();
	solve();
	output();
}
