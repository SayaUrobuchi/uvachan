/*
ID: dd.ener1
PROG: palsquare
LANG: C++
*/
#include <fstream>
using namespace std;

long B;

bool is_pals(const string& s){
	long l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r])return false;
		++l;--r;
	}
	return true;
}
void reverse(string& s){
	long l=0,r=s.length()-1;
	while(l<r){
		char t=s[l];
		s[l]=s[r];
		s[r]=t;
		++l;--r;
	}
}
string Num2Str(long n){
	static const char set[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	string res;
	do{
		res+=set[n%B];
		n/=B;
	}while(n!=0);
	reverse(res);
	return res;
}
int main(){
	{
		ifstream cin("palsquare.in");
		cin>>B;
	}
	ofstream cout("palsquare.out");
	for(long i=1;i<=300;++i){
		string str2=Num2Str(i*i);
		if(is_pals(str2))
			cout<<Num2Str(i)<<' '<<str2<<endl;
	}
	return 0;
}
