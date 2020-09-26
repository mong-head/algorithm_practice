#include <iostream>

using namespace std;

int main()
{
  int R[13];
  R[0] = 0;
  R[1] = 1;
  R[2] = 2;
  R[3] = 4;

  for(int i=4;i<13;i++)
  {
    R[i] = R[i-1]+R[i-2]+R[i-3];
  }

  int num_test; //test case 수
  cin >> num_test;
  int n[num_test];
  for(int i=0;i<num_test;i++)
  {
    int tmp;
    cin >> tmp;
    n[i] = R[tmp];
  }

  for(int i=0;i<num_test;i++)
  {
    cout << n[i]<<'\n';
  }

  return 0;
}
