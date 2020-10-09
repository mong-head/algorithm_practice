#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class false_r{
    public:
    int stage;
    double false_rate;
    false_r(int s, double fr){stage=s;false_rate=fr;}
    bool operator<(false_r& f){
      if(this->false_rate == f.false_rate) return this->stage < f.stage;
      else return this->false_rate > f.false_rate;
    }
};


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<false_r> f;
    int size,num_f;
    double rate;

    sort(stages.begin(),stages.end());

    for(int i=1;i<N+1;i++){
        size = stages.size();
        num_f=0;
        while(stages.front()==i&&stages.size()>0){
            stages.erase(stages.begin());
            num_f++;
        }
        if(size==0)rate = 0;
        else rate = (double)num_f/size;
        false_r tmp(i,rate);
        f.push_back(tmp);
    }
    sort(f.begin(),f.end());
    for(auto& a : f){
        answer.push_back(a.stage);
    }

    return answer;
}
int main(){
  vector<int> stages = {2,1,2,6,2,4,3,3};
  //vector<int> stages = {4,4,4,4,4};
  vector<int> s = solution(5,stages);
  for(auto& a : s){
    cout << a;
  }
}
