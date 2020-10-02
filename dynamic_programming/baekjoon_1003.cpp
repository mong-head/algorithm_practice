#include <iostream>
using namespace std;

int main()
{
  //inputs
  int n;
  cin >> n;
  int test_case[n];
  for(int i=0;i<n;i++)
  {
    cin >> test_case[i];
  }

  //DP
  long DP_fibo[41];
  DP_fibo[0] = 0;
  DP_fibo[1] = 1;

  for(int i=2;i<=40;i++){
    DP_fibo[i] = DP_fibo[i-1]+DP_fibo[i-2];
  }




  return 0;
}
