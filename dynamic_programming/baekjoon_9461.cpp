#include <iostream>
using namespace std;

int main()
{
  //inputs
  int T;
  cin >> T;
  int test_case[T];
  for(int i=0;i<T;i++) cin >> test_case[i];

  //DP
  long long P[101]={0,1,1,1,2,2,3,4,5,7,9};
  for(int i=11;i<=100;i++){
    P[i] = P[i-1]+P[i-5];
  }

  //outputs
  for(int i=0;i<T;i++)cout << P[test_case[i]]<<endl;

  return 0;
}
