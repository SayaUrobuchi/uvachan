#include "vectorfunctions.h"
#include <algorithm>
using namespace std;

void backwards(std::vector<int>& vec){
	reverse(vec.begin(), vec.end());
}

std::vector<int> everyOther(const std::vector<int>& vec){
    vector<int> ret;
    int i;
    for (i=0; i<vec.size(); i+=2)
    {
    	ret.emplace_back(vec[i]);
    }
    return ret;
}

int smallest(const std::vector<int>& vec){
	int ret = vec[0];
	int i;
	for (i=1; i<vec.size(); i++)
	{
		ret = min(ret, vec[i]);
	}
	return ret;
}

int sum(const std::vector<int>& vec){
	int ret = 0;
	int i;
	for (i=0; i<vec.size(); i++)
	{
		ret += vec[i];
	}
	return ret;
}

int veryOdd(const std::vector<int>& vec){
	int ret = 0;
	int i;
	for (i=1; i<vec.size(); i+=2)
	{
		ret += (vec[i] & 1);
	}
	return ret;
}
