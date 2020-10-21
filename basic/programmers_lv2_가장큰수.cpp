#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class make_num{
    public:
    int original;
    int fake;
    make_num(int n){original=n;}
    void patching(){
        fake = original;
        int tmp = original;
        int iter = 1000;
        if(fake!=0){
            while(iter>0){
                if(tmp/iter==0) fake *= 10;
                else tmp/=10;
                iter /= 10;
            }
        }
    }
    bool operator<(make_num& a){
        if(this->fake == a.fake) return this->original < a.original;
        return this->fake > a.fake;
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    vector<make_num> fakes;

    for(auto& n : numbers){
        make_num tmp(n);
        tmp.patching();
        fakes.push_back(tmp);
    }
    sort(fakes.begin(),fakes.end());
    for(auto& c : fakes){
        cout << c.fake << ' ';
    }
    int count = 0;
    for(auto& fake : fakes){
        if(fake.original){
        answer += to_string(fake.original);
        }
        else if(answer!="") answer += "0";
    }
    if(answer=="") answer += "0";
    return answer;
}
