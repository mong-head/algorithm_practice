#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){

  int n,m;
  cin >> n >> m;
  char board[n][m]; //구슬이 움직이는 판
  pair<int,int> rbo[3]; //rbo[0]:r,rbo[1]:b,rbo[2]:o 위치

  //입력
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cin >> board[i][j];
      switch(board[i][j]){
        case 'R':
          rbo[0] = make_pair(i,j);
          break;
        case 'B':
          rbo[1] = make_pair(i,j);
          break;
        case 'O':
          rbo[2] = make_pair(i,j);
          break;
      }
  }

  return 0;
}

void

bool rule(pair<int,int> r,pair<int,int> b){
  if(r != b){
    if(r == 'O'){
      if(b != 'O'){
        return true;
      }
    }
  }
  return false;
}
