#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    long long sum = 0;
    const char * digit[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    cin>>input;
    for (long i = 0;i < input.size();++i){
        sum += (input[i] - '0');
    }
    vector<int> result;
    if (sum == 0) result.push_back(0);
    else
        while (sum){
            result.push_back(sum % 10);
            sum /= 10;
        }
    for (vector<int>::reverse_iterator it = result.rbegin();it != result.rend();++it){
        cout<<digit[*it];
        if (++it != result.rend()) cout<<" ";
        --it;
    }
    cout<<endl;

    return 0;
}

