/*
ID: dd.ener1
PROG: transform
LANG: C++
*/
#include <fstream>
#include <cstdlib>
using namespace std;

long N;
char s1[12][12];
char s2[12][12];
char x1[12][12];
char x2[12][12];

void input(){
	ifstream cin("transform.in");
	cin>>N;
	for(long i=0;i<N;++i){
		cin.ignore();
		for(long j=0;j<N;++j)s1[i][j]=cin.get();
	}
	for(long i=0;i<N;++i){
		cin.ignore();
		for(long j=0;j<N;++j)s2[i][j]=cin.get();
	}
}
void do1(){
	//(x,y)->(y,N-1-x)
	for(long x=0;x<N;++x)
		for(long y=0;y<N;++y)
			x1[y][N-1-x]=s1[x][y];	
}
void do2(){
	//(x,y)->(N-1-x,N-1-y)
	for(long x=0;x<N;++x)
		for(long y=0;y<N;++y)
			x1[N-1-x][N-1-y]=s1[x][y];
}
void do3(){
	//(x,y)->(N-1-y,x)
	for(long x=0;x<N;++x)
		for(long y=0;y<N;++y)
			x1[N-1-y][x]=s1[x][y];
}
void do4(){
	//(x,y)->(x,N-1-y)
	for(long x=0;x<N;++x)
		for(long y=0;y<N;++y)
			x1[x][N-1-y]=s1[x][y];	
}
void do5(){
	for(long x=0;x<N;++x)
		for(long y=0;y<N;++y)
			x2[x][N-1-y]=x1[x][y];
}
void do51(){
	do1();
	do5();
}
void do52(){
	do2();
	do5();
}
void do53(){
	do3();
	do5();
}
bool test(char a[12][12],char b[12][12]){
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			if(a[i][j]!=b[i][j])return false;
	return true;
}
void suc(int n){
	ofstream cout("transform.out");
	cout<<n<<endl;
	exit(0);
}
int main(){
	input();
	do1();
	if(test(s2,x1))suc(1);
	do2();
	if(test(s2,x1))suc(2);
	do3();
	if(test(s2,x1))suc(3);
	do4();
	if(test(s2,x1))suc(4);
	do51();
	if(test(s2,x2))suc(5);
	do52();
	if(test(s2,x2))suc(5);
	do53();
	if(test(s2,x2))suc(5);
	if(test(s1,s2))suc(6);
	suc(7);
}
