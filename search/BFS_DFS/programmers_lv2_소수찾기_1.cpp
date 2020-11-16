#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set<int> result_per;
vector<char> v;
string s;
int max_;
void permutation(string& nums, vector<bool>& check, int n, int r){
  if(n==r){
    s = "";
    for(auto& a : v) s += a;
    int result = stoi(s);
    result_per.insert(result);
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

bool is_prime(int a){
  int len = sqrt(a);
  for(int i=2;i<=len;i++){
    if(a%i==0) return false;
  }
  return true;
}
int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    vector<bool> check(len,false);
    max_ = len;
    for(int i=1;i<=len;i++){
        permutation(numbers,check,0,i);
    }
    for(auto& result : result_per){
      if(result > 1){
        if(is_prime(result)) answer++;
      }
    }
    return answer;
}

int main(){
  string numbers = "17";
  cout << solution(numbers);
}
