#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(auto& b : d){
        if(b > budget) break;
        budget -= b;
        answer++;
    }
    return answer;
}
