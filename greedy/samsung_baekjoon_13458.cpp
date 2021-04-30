#include <iostream>
#include <vector>

using namespace std;

int main()
{
  //입력
  int N,A,B,C;
  cin >> N;
  int room[N]; //시험장
  for(int i=0;i<N;i++) cin >> room[i];
  cin >> B >> C;

  //결과
  int result = N; //각 방마다 감독관은 한 명 씩 있으므로

  for(int i=0;i<N;i++){
    room[i] -= B; //주감독관이 감독할 수 있는 수를 뺌
  }
  for(int i=0;i<N;i++){
    if(room[i]<=0) continue;
    else if(room[i]%C) result += 1;

    result += room[i]/C;
  }
  cout << result;
  return 0;
}
