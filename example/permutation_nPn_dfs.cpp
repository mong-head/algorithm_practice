#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
void permutation(vector<int>& list, int start, int end){
  if(start == end){
    for(auto& l : list) cout << l << ' ';
    cout << '\n';
    return;
  }
  else{
    for(int i=start;i<N;i++){
      swap(list[start],list[i]);
      permutation(list,start+1,end);
      swap(list[start],list[i]); //원래 대로 되돌림
    }
  }
}

int main(){
  vector<int> num = {0,1,1};
  N = num.size();
  permutation(num,0,N);
  return 0;
}
