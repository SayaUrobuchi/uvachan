/*
ID: dd.ener1
PROG: beads
LANG: C++
*/

#include <fstream>
using namespace std;

long N;
char* S;
void input(){
	ifstream cin("beads.in");
	cin>>N;
	S=new char[N];
	cin.ignore();
	for(long i=0;i<N;++i)
		S[i]=cin.get();
}
inline bool same(char c1,char c2){
	if(c1=='w'||c2=='w')return true;
	return c1==c2;
}
long testr(long i){
	char c='b';
	long res1;
	for(res1=0;res1<N&&same(c,S[(i+res1+N)%N]);++res1);
	c='r';
	long res2;
	for(res2=0;res2<N&&same(c,S[(i+res2+N)%N]);++res2);
	return res1>res2?res1:res2;
}
long testl(long i){
	char c='b';
	long res1;
	for(res1=0;res1<N&&same(c,S[(i-res1+N)%N]);++res1);
	c='r';
	long res2;
	for(res2=0;res2<N&&same(c,S[(i-res2+N)%N]);++res2);
	return res1>res2?res1:res2;
}
inline void update(long& old,long updater){
	if(old<updater)old=updater;
}
long solve(){
	long best=-1;
	for(long i=0;i<N;++i)
		update(best,testr(i)+testl((i-1+N)%N));
	return best>N?N:best;
}
int main(){
	input();
	ofstream cout("beads.out");
	cout<<solve()<<endl;
}
