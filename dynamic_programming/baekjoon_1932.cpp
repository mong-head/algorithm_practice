#include <iostream>

using namespace std;

int main()
{
  //inputs
  int n;
  cin >> n;

  int cost[n][n]; //현재 수
  int sub[n][n]; //전까지 수의 합 중 최대

  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++) cin >> cost[i][j];
  }

  //DP
  sub[0][0] = cost[0][0];
  for(int i=1;i<n;i++){
    sub[i][0] = sub[i-1][0] + cost[i][0];
    sub[i][i] = sub[i-1][i-1] + cost[i][i];
    for(int j=1;j<i;j++){
      sub[i][j] = max(sub[i-1][j-1],sub[i-1][j]) + cost[i][j];
    }
  }

  //output
  int max=sub[n-1][0];
  for(int i=1;i<n;i++){
    if(max < sub[n-1][i]) max = sub[n-1][i];
  }
  cout << max;
  return 0;
}
