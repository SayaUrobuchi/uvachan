/*
ID: dd.ener1
PROG: castle
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

long M,N;
long s[60][60];
long room[60][60];//记录每个格子属于几号房间
basic_string<long> size;//记录每个房间的大小 


void input(){
	ifstream cin("castle.in");
	cin>>M>>N;
	for(long i=0;i<N;++i)
		for(long j=0;j<M;++j)
			cin>>s[i][j];
	memset(room,-1,sizeof(room));
}
bool has_north(long i,long j){
	if(s[i][j]&2)return false;
	return true;
}
bool has_south(long i,long j){
	if(s[i][j]&8)return false;
	return true;
}
bool has_west(long i,long j){
	if(s[i][j]&1)return false;
	return true;
}
bool has_east(long i,long j){
	if(s[i][j]&4)return false;
	return true;
}
void flood(long i,long j){
	if(room[i][j]!=-1)return;
	room[i][j]=size.length()-1;
	++(size[room[i][j]]);
	if(has_north(i,j))flood(i-1,j);
	if(has_south(i,j))flood(i+1,j);
	if(has_west(i,j))flood(i,j-1);
	if(has_east(i,j))flood(i,j+1);
}
void floodfill(){
	for(long i=0;i<N;++i)
		for(long j=0;j<M;++j)
			if(room[i][j]==-1){
				size+=long(0);
				flood(i,j);
			}
}
void output(){
	ofstream cout("castle.out");
	cout<<size.length()<<endl;
	{
		long big=-1;
		for(long i=size.length()-1;i>=0;--i)
			if(size[i]>big)big=size[i];
		cout<<big<<endl;
	}
	//枚举墙
	long big=-1,nn,mm,WorS;
	for(long j=0;j<M;++j)
		for(long i=N-1;i>=0;--i){
			if(j!=0&&room[i][j]!=room[i][j-1]){
				long now=size[room[i][j]]+size[room[i][j-1]];
				if(now>big){
					big=now;
					nn=i;mm=j;
					WorS=true;
				}
			}
			if(i!=N-1&&room[i][j]!=room[i+1][j]){
				long now=size[room[i][j]]+size[room[i+1][j]];
				if(now>big){
					big=now;
					nn=i;mm=j;
					WorS=false;
				}
			}
		}
	cout<<big<<endl;
	if(WorS)
		cout<<nn+1<<' '<<mm<<" E"<<endl;
	else
		cout<<nn+2<<' '<<mm+1<<" N"<<endl;
}
int main(){
	input();
	floodfill();
	output();
}
