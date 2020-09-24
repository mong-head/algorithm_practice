#include <iostream>

using namespace std;

int main(){
  int N,K;

  //input
  cin >> N >> K;

  int* arr = new int[N];
  for(int i=0;i<N ; i++) cin >> arr[i];

  int coin = 0;
  int left = K;
  for(int i=N-1; i>-1; i--)
  {
    if(arr[i] < K)
    {
      coin += left / arr[i];
      left %= arr[i];
    }
  }

  cout << coin;

  delete[] arr;
  return 0;
}
