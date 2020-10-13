#include <iostream>
using namespace std;

int main(){
  //inputs
  int n;
  cin >> n;
  int cost[n+1]; //각 계단의 점수
  cost[0] = 0; //시작점
  for(int i=1;i<n+1;i++) cin >> cost[i];

  //DP
  int sub[n+1]; //각 계단까지 오는데 최대 점수
  sub[0] = 0;
  sub[1] = cost[1];
  if(n>1){
    sub[2] = cost[1]+cost[2];
    for(int i=3;i<n+1;i++){
      sub[i] = max(sub[i-2],sub[i-3]+cost[i-1]) + cost[i];
    }
  }

  //output
  cout << sub[n];
  return 0;
}
