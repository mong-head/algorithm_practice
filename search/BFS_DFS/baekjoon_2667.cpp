#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 25

using namespace std;

int n;
int house[MAX][MAX];
bool visited[MAX][MAX]; //false로 초기화
int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}}; //상하좌우
vector<int> counts;
int count_;

void dfs(int x,int y);
int main(){
  //inputs
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%1d",&house[i][j]);
    }
  }

  //search
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(visited[i][j]==false && house[i][j]){
        count_ = 0;
        dfs(i,j);
        counts.push_back(count_);
      }
    }
  }
  sort(counts.begin(),counts.end());
  cout << counts.size()<<endl;
  for(auto& c : counts){
    cout <<c<<endl;
  }

  return 0;
}

void dfs(int x,int y){
  count_++;
  visited[x][y] = true;

  int next_x,next_y;
  for(int i=0;i<4;i++){
    next_x = x+dir[0][i];
    next_y = y+dir[1][i];
    if(0<=next_x&&next_x<n && 0<=next_y&&next_y<n){
      if(visited[next_x][next_y]==false && house[next_x][next_y])
        dfs(next_x,next_y);
    }
  }
}
