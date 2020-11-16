#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> result_per;
vector<char> v;
string s;
int max_;
void permutation(string& nums, vector<bool>& check, int n, int r){
  if(n==r){
    s = "";
    for(auto& a : v) s += a;
    result_per.push_back(s);
    return;
  }
  else{
    for(int i=0;i<max_;i++){
      if(check[i]== false){
        check[i] = true;
        v.push_back(nums[i]);
        permutation(nums,check,n+1,r);
        v.pop_back();
        check[i] = false;
      }
    }
  }
}

int main(){
  vector<bool> check = {false,false,false};
  string numbers = "011";
  max_ = 3;
  permutation(numbers,check,0,3);
  for(auto& a : result_per) cout << a << ' ';
  cout <<endl;

  return 0;
}
