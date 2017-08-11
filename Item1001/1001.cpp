/*************************************************************************
    > File Name: 1001.cpp
    > Author: 关山月朦胧
    > Mail: 1036014410@qq.com
    > Created Time: Fri 11 Aug 2017 06:53:40 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void formatInt (int num){
	int tmp = abs(num);
	string numStr;
	if (num == 0){
		cout<<'0';
		return;
	}
	while (tmp){
		numStr.push_back(tmp % 10 + '0');
		tmp /= 10;
	}
	reverse(numStr.rbegin(),numStr.rend());

	size_t high = numStr.size() % 3;
	size_t i = 0;

	if (num < 0) cout<<'-';
	if (high != 0){
		size_t tmphigh = high;
		while(tmphigh--){
			cout<<numStr[i];
			++i;
		}
		if (i < numStr.size()) cout<<',';
		else return;
	}

	for (;i < numStr.size();++i){
		if ((i - high) % 3 == 2 && numStr.size() - i >= 2){
			cout<<numStr[i]<<',';
		}
		else 
			cout<<numStr[i];
	}
}
int main(int argc,char **argv){
	int left,right,result;
	cin>>left>>right;
	result = left + right;
	formatInt(result);
	return 0;
}
