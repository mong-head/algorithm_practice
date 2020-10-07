#include <string>
#include <vector>

using namespace std;
//효율 제로
int solution(int n) {
    int answer = 1;
    int i,j;
    for(i=3;i<=n;i+=2){
        for(j=2;j<i;j++){
            if(i%j==0) break;
        }
        if(i==j) answer++;
    }
    return answer;
}
