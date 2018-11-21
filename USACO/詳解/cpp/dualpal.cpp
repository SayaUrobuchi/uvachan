/*
ID: dd.ener1
PROG: dualpal
LANG: C++
*/
#include <fstream>
using namespace std;

bool is_pals(const string& s){
	long long l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r])return false;
		++l;--r;
	}
	return true;
}
string Num2Str(long long n,long long B){
	static const char set[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	string res;
	do{
		res+=set[n%B];
		n/=B;
	}while(n!=0);
	return res;
}
int main(){
	long long n,s;
	{
		ifstream cin("dualpal.in");
		cin>>n>>s;
	}
	ofstream cout("dualpal.out");
	do{
		++s;
		long times=0;
		for(long b=2;b<=10;++b){
			if(is_pals(Num2Str(s,b)))++times;
			if(times>=2){
				cout<<s<<endl;
				--n;
				break;
			}
		}
	}while(n);
	return 0;
}
