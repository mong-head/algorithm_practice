#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int maze[101][101];

int dir[2][4] = {{0,1,0,-1},{1,0,-1,0}};
void dfs(int x,int y);
int count;

int main()
{
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      scanf("%1d",&maze[i][j]);
  }
  dfs(0,0);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cout << maze[i][j] << ' ';
    cout <<endl;
  }
  cout << maze[n-1][m-1];
  return 0;
}
void dfs(int x,int y){
  if(count == 1) return;
  if(x==(n-1) && y==(m-1)){
    count = 1;
  }
  int new_x,new_y;
  for(int j=0;j<4;j++){
    new_x = x + dir[0][j];
    new_y = y + dir[1][j];
    if(-1<new_x&&new_x<n &&-1<new_y&&new_y<m){
      if(maze[new_x][new_y]==1){
        maze[new_x][new_y] = maze[x][y]+1;
        cout << maze[x][y] <<endl;
        cout << new_x << new_y << endl;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++)
            cout << maze[i][j] << ' ';
          cout <<endl;
        }
        cout <<endl;
        dfs(new_x,new_y);

      }
    }
  }


}
