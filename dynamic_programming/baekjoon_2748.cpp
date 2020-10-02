#include <iostream>

using namespace std;

int main()
{
  long DP_fibo[95];
  DP_fibo[0] = 0;
  DP_fibo[1] = 1;

  int n;
  cin >> n;
  for(int i=2;i<=n;i++){
    DP_fibo[i] = DP_fibo[i-1]+DP_fibo[i-2];
  }
  cout <<DP_fibo[n];

  return 0;
}
