#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m){
    if(n < m) swap(n,m);
    if(n%m == 0) return m;
    else return GCD(m, n%m);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(GCD(n,m));
    answer.push_back(answer[0]*(n/answer[0])*(m/answer[0]));
    return answer;
}
