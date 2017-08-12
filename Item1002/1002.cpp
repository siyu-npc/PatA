/*************************************************************************
    > File Name: 1002.cpp
    > Author: 关山月朦胧
    > Mail: 1036014410@qq.com
    > Created Time: Sat 12 Aug 2017 09:54:03 AM CST
 ************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 1001

int main(int argc,char **argv){
	double coefficients[MAX] = {0.0};
	double coefficients_2[MAX] = {0.0};
	int n;
	int max_exp = 0;
	int cnt = 0;

	int readtime = 2;
	while(readtime--){
		int n = 0;
		cin>>n;
		while(n--){
			int exp;
			double coe;
			cin>>exp>>coe;
			coefficients[exp] += coe;
			if (exp > max_exp) max_exp = exp;
		}
	}
	for (int i = 0;i <= max_exp;++i)
		if (coefficients[i] != 0.0) ++cnt;

	if (cnt == 0){
		cout<<0<<endl;
		return 0;
	}
	cout<<cnt;
	cout<<fixed<<setprecision(1);
	for (int i = max_exp;i >= 0;--i){
		if (coefficients[i] != 0.0)
			cout<<" "<<i<<" "<<coefficients[i];
	}
	return 0;
}
