#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

set<int> result_per;
vector<char> v;
string s;
int max_;

//string으로 구할 수 있는 모든 경우의 수 구하기
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

//에라토스테네스 이용
set<int> is_prime_Era(int n) {
    int answer = 0;
    int prime[n+1];
    for(int i=0;i<=n;i++) prime[i] = i;

    for(int i=2;i<=n;i++){
        if(prime[i]!=0){
            for(int j=i*2;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }

    set<int> prime_set;
    for(int i=2;i<=n;i++){
        if(prime[i]) prime_set.insert(prime[i]);
    }
    return prime_set;
}
bool compare(int a, int b){
  //큰거앞 정렬
  return a>b;
}
int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();

    //모든 경우의 수 구하기
    vector<bool> check(len,false);
    max_ = len;
    for(int i=1;i<=len;i++){
        permutation(numbers,check,0,i);
    }

    //prime 목록 구하기-에라토스테네스의 체
    sort(numbers.begin(),numbers.end(),compare);
    set<int> prime = is_prime_Era(stoi(numbers));

    //교집합 구하기
    unordered_map<int, int> all_prime;
    for(auto& per : result_per) all_prime[per]++;
    for(auto& pri : prime) all_prime[pri]++;

    for(pair<int,int> a : all_prime){
        if(a.second == 2) {
          //cout << a.first<<endl;
          answer++;
        }
    }
    return answer;
}

int main(){
  string numbers = "17";
  cout << solution(numbers);
}
