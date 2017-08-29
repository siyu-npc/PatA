#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX 100

struct Person{
    int id;
    int childnum;
    int parent;
    int level;
    Person():id(-1),childnum(0),parent(-1),level(-1){};
};

int main()
{
    vector<Person> tree[MAX];
    Person person[MAX];
    map<int,int> result;
    int n,m;
    cin>>n>>m;
    if (n == 1) cout<<1<<endl;
    else {
        for (int i = 0;i < m;++i){
            int id,k;
            cin>>id>>k;
            person[id].id = id;
            person[id].childnum = k;
            if (id == 1) person[1].parent = 0;//将root的parent设置为0
            for (int i = 0;i < k;++i){
                int tmp;
                cin>>tmp;
                person[tmp].parent = id;
                person[tmp].id = tmp;
            }
        }

        for (int i = 0;i < MAX;++i){
            if (person[i].id != -1){
                person[i].level = person[person[i].parent].level + 1;
            }
        }
        for (int i = 0;i < MAX;++i) {
            if (person[i].id != -1) {
                result[person[i].level];
                if (person[i].childnum == 0)
                    result[person[i].level] += 1;
            }
        }
        for (map<int,int>::iterator it = result.begin();it != result.end();++it){
            cout<<(*it).second;
            if (++it != result.end()){
                cout<<" ";
            }
            --it;

        }

        cout<<endl;
    }
    return 0;
}

