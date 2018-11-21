/*
ID: dd.ener1
PROG: lgame
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int scores[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};

string ss[10000];
int sc[10000];
string S;
int N;
int ch[26];
string res[1000];
int R;
int max1;

bool valid(const string& s){
	static int ch2[26];
	for(int i=0;i<26;++i)
		ch2[i]=0;
	for(int i=s.size()-1;i>=0;--i)
		ch2[s[i]-'a']++;
	for(int i=0;i<26;++i)
		if(ch2[i]>ch[i])return false;
	return true;
}
bool valid(const string& s1,const string& s2){
	static int ch2[26];
	for(int i=0;i<26;++i)
		ch2[i]=0;
	for(int i=s1.size()-1;i>=0;--i)
		ch2[s1[i]-'a']++;
	for(int i=s2.size()-1;i>=0;--i)
		ch2[s2[i]-'a']++;
	for(int i=0;i<26;++i)
		if(ch2[i]>ch[i])return false;
	return true;
}
int score(const string& s){
	int res=0;
	for(int i=s.size()-1;i>=0;--i)
		res+=scores[s[i]-'a'];
	return res;
}
inline void add_res(const string& s){
	res[R++]=s;
}
inline void re_res(const string& s){
	res[0]=s;
	R=1;
}
inline string link(const string& s1,const string& s2){
	if(s1<s2)return s1+' '+s2;
	else return s2+' '+s1;
}
int main(){
	freopen("lgame.in","r",stdin);
	getline(cin,S);
	for(int i=S.size()-1;i>=0;--i)
		ch[S[i]-'a']++;
	freopen("lgame.dict","r",stdin);
	N=0;
	for(;;){
		string s;
		getline(cin,s);
		if(s==".")break;
		if(valid(s)){
			ss[N]=s;
			int sco=score(s);
			sc[N++]=sco;
			if(sco>=max1)max1=sco;
		}
	}
	for(int i=0;i<N;++i){
		if(sc[i]==max1)
			add_res(ss[i]);
	}
	for(int i=N-1;i>=0;--i)
		for(int j=0;j<i;++j){
			if(sc[i]+sc[j]<max1)continue;
			if(valid(ss[i],ss[j]))
				if(sc[i]+sc[j]>max1){
					max1=sc[i]+sc[j];
					re_res(link(ss[i],ss[j]));
				}
				else if(sc[i]+sc[j]==max1)
					add_res(link(ss[i],ss[j]));
		}
	sort(res,res+R);
	freopen("lgame.out","w",stdout);
	cout<<max1<<endl;
	for(int i=0;i<R;++i)
		cout<<res[i]<<endl;
}
