#include <iostream>
#include <vector>
using namespace std;

int main()
{
  //inputs
  int n;
  cin >> n;
  int test_case[n];
  for(int i=0;i<n;i++){
    cin >> test_case[i];
  }

  vector<int> zero = {1,0};
  vector<int> one = {0,1};

  for(int i=0;i<40;i++){
    zero.push_back(zero[i]+zero[i+1]);
    one.push_back(one[i]+one[i+1]);
  }

  for(int i=0;i<n;i++){
    cout << zero[test_case[i]] << ' '<<one[test_case[i]]<<endl;
  }

  return 0;
}
