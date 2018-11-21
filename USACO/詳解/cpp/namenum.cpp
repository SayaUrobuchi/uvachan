/*
ID: dd.ener1
PROG: namenum
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


string trans(const string& s){
	/*
	2: A,B,C     5: J,K,L    8: T,U,V
	3: D,E,F     6: M,N,O    9: W,X,Y
	4: G,H,I     7: P,R,S
	*/
	char d[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7',-1,'7','7','8','8','8','9','9','9',-1};
	string r;
	int l=s.size();
	for(int i=0;i<l;++i)
		r+=d[s[i]-'A'];
	return r;
}
int main(){
	string num;
	freopen("namenum.in","r",stdin);
	cin>>num;
	int l=num.size();

	bool out=false;
	freopen("dict.txt","r",stdin);
	freopen("namenum.out","w",stdout);
	string s;
	while(cin>>s){
		if(s.size()!=l)continue;
		if(num==trans(s)){
			out=true;
			puts(s.c_str());
		}
	}
	if(out==false)
		puts("NONE");
}
