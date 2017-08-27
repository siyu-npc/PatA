/*************************************************************************
    > File Name: 1003.cpp
    > Author: 关山月朦胧
    > Mail: 1036014410@qq.com
    > Created Time: Sat 12 Aug 2017 04:12:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 501;

int Map[MAX][MAX];
bool visited[MAX];
int length[MAX];//记录每个地点到起始点的最短距离
int cnt = 1;
int help = 0;
int teams[MAX];
unsigned int minLength = (unsigned)-1;

void dfs(int from,int to,int cityNumber,int len,int helper){//参数len记录了from到起始点的最短距离
	if (length[from] > minLength) return;
	else {
//		if (from == to && len == minLength) ++cnt;
		if (from == to){
			if (len < minLength) {
				cnt = 1;
				minLength = len;
				help = helper;
			}
			else if (len == minLength){
				++cnt;
				if (help < helper) help = helper;
			}
		}
		else {
			for (int i = 0;i < cityNumber;++i){

				if (!visited[i] && Map[from][i] != -1){
					if (Map[from][i] + length[from] <= (unsigned int)length[i]){
						length[i] = length[from] + Map[from][i];
						len = length[i];
						visited[i] = true;
						dfs(i,to,cityNumber,len,helper + teams[i]);
						visited[i] = false;
					}
				}
			}
		}
	}
}
int main(int argc,char **argv){
	int n,m,cut,dst;
	cin>>n>>m>>cut>>dst;
	for (int i = 0;i < n;++i){
		cin>>teams[i];
	}
	for (int i = 0;i < MAX;++i){
		for (int j = 0;j < MAX;++j) Map[i][j] = -1;
		Map[i][i] = 0;
		length[i] = -1;
	}

	visited[cut] = true;
	length[cut] = 0;
	int row,col;
	for (int i = 0;i < m;++i){
		int tmp;
		cin>>row>>col>>tmp;
		Map[col][row] = Map[row][col] = tmp;
	}


	int l = 0;
	dfs(cut,dst,n,l,teams[cut]);
	cout<<cnt<<" "<<help<<endl;

	return 0;
}

