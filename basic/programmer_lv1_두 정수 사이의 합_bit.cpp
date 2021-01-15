#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    return answer;
}
//(b(b+1)/2 - a(a-1)/2) 1부터 b까지 더한 것에서 1부터 a-1까지 더한 것을 뺌
// 합친다면, (b+a)(abs(b-a)+1)/2로 한 줄에 끝낼 수 있음