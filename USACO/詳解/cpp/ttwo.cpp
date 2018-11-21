/*
ID: dd.ener1
PROG: ttwo
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long N=10;
char map[12][12];
long X[2],Y[2],dir[2];
bool visit[N][N][4][N][N][4]; 
/*
Direction: 
0:North
1:East
2:South
3:West
*/
void input(){
	freopen("ttwo.in","r",stdin);
	for(long i=0;i<N;++i){
		gets(map[i]);
	}
}
void initXY(){
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j){
			if(map[i][j]=='F'){
				X[0]=i;
				Y[0]=j;
			}
			else if(map[i][j]=='C'){
				X[1]=i;
				Y[1]=j;
			}
		}
	dir[0]=dir[1]=0;
}
bool cango(long x,long y){
	if(x<0||y<0||x>=N||y>=N)return false;
	if(map[x][y]=='*')return false;
	return true;
}
void goNext(long k){
	long nextX,nextY;
	switch(dir[k]){
		case 0:
			nextX=X[k]-1;
			nextY=Y[k];
			break;
		case 1:
			nextX=X[k];
			nextY=Y[k]+1;
			break;
		case 2:
			nextX=X[k]+1;
			nextY=Y[k];
			break;
		case 3:
			nextX=X[k];
			nextY=Y[k]-1;
	}
	if(cango(nextX,nextY)){
		X[k]=nextX;
		Y[k]=nextY;
	}
	else{
		++dir[k];
		dir[k]%=4;
	}
}
long solve(){
	memset(visit,0,sizeof(visit));
	long res=0;
	initXY();
	for(;;){
		goNext(0);
		goNext(1);
		++res;
		if(X[0]==X[1]&&Y[0]==Y[1])return res;
		if(visit[X[0]][Y[0]][dir[0]][X[1]][Y[1]][dir[1]])return 0;
		visit[X[0]][Y[0]][dir[0]][X[1]][Y[1]][dir[1]]=true;
	}
}
void output(long res){
	freopen("ttwo.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	output(solve());
}
