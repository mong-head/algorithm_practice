#include <string>
#include <vector>
#include <cmath>

using namespace std;
//에라토스테네스의 체 사용
int solution(int n) {
    int answer = 0;
    int prime[1000001];
    for(int i=0;i<=n;i++) prime[i] = i;

    for(int i=2;i<=n;i++){
        if(prime[i]!=0){
            for(int j=i*2;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) answer++;
    }
    return answer;
}
