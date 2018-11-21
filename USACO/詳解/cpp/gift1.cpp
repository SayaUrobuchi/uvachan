/*
ID: dd.ener1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

long NP;
string* names;
long* gived;
long* received;

ifstream cin("gift1.in");
ofstream cout("gift1.out");

void init(){
	cin>>NP;
	names=new string[NP];
	gived=new long[NP];
	memset(gived,0,sizeof(long)*NP);
	received=new long[NP];
	memset(received,0,sizeof(long)*NP);
	for(long i=0;i<NP;++i)cin>>names[i];
}
long getnum(string s){
	for(long i=0;i<NP;++i)if(names[i]==s)return i;
	return -1;
}
void solve(){
	for(long i=0;i<NP;++i){
		string s;
		long money,NG;
		cin>>s>>money>>NG;
		if(NG==0)continue;
		long gift1=money/NG;
		gived[getnum(s)]=NG*gift1;
		for(long j=0;j<NG;++j){
			string p2;
			cin>>p2;
			received[getnum(p2)]+=gift1;
		}
	}
}
void output(){
	for(long i=0;i<NP;++i)
		cout<<names[i]<<' '<<received[i]-gived[i]<<endl;
}
int main(){
	init();
	solve();
	output();
	return 0;
}
