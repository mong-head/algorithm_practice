#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string rv="";
    while(n>0){
        rv += to_string(n%3);
        n /=3;
    }
    int size = rv.size();
    int j=1;
    for(int i=size-1;i>-1;i--){
        answer += (rv[i]-'0')*j;
        j *= 3;
    }
    return answer;
}
