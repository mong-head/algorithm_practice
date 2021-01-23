#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> skill_map;
    int order_ = 1;
    for(auto& s : skill) skill_map[s] = order_++;
    for(auto& tree : skill_trees){
        int temp = 1;
        int flag = 1;
        for(auto& t : tree){
            if(flag==0) break;
            if(skill_map[t]>0){
                if(skill_map[t] != temp) flag = 0;
                else temp++;
            }
        }
        if(flag == 1)
            answer++;
    }
    return answer;
}