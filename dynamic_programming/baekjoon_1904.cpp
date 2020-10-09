#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;

  unsigned long long tile[1000001];
  tile[1] = 1;
  tile[2] = 2;
  for(int i=3;i<=n;i++) {
    tile[i]=tile[i-1]+tile[i-2];
    tile[i]%=15746;
  }
  cout << tile[n];
  return 0;
}
