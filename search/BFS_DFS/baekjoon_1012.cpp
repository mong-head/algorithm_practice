#include <iostream>
#include <cstring>
using namespace std;

bool farm[50][50];
bool visit[50][50];
int count;

int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};
int t,n,m,k; //test case, 가로, 세로, 배추 개수

void dfs(int x,int y);
int main()
{
  //inputs
  cin >> t;
  int answer[t];
  for(int i=0;i<t;i++){
    cin >> n >> m >> k;
    //farm, visit배열 모두 false로 만들기
    memset(farm,false,sizeof(farm));
    memset(visit,false,sizeof(visit));
    count = 0;

    int x,y;
    for(int j=0;j<k;j++){
      cin >> x >> y;
      farm[x][y] = true;
    }
    for(x = 0;x<n;x++){
      for(y = 0;y<m;y++){
        if(farm[x][y] && !visit[x][y]){
          dfs(x,y);
          count++;
        }
        visit[x][y] = true;
      }
    }
    answer[i] = count;
  }

  for(int i=0;i<t;i++) cout << answer[i] <<endl;
  return 0;
}
void dfs(int x,int y){
  visit[x][y] = true;

  int new_x, new_y;
  for(int i=0;i<4;i++){
    new_x = x + dir[0][i];
    new_y = y + dir[1][i];
    if(-1<new_x&&new_x<n && -1<new_y&&new_y<m){ //없으면 런타임 에러
      if(farm[new_x][new_y] && !visit[new_x][new_y]){
        dfs(new_x,new_y);
      }
    }
  }
}
