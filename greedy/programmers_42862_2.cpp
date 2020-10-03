#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[n+2]; // 0,n+1 추가로
    fill_n(student,n+2,1); //체육복 모두 가지고 있는 상태

    for(int i : lost) student[i]--;
    for(int i : reserve) student[i]++;

    for(int i=1;i<=n;i++){
        if(student[i] == 0){
            if(student[i-1] == 2) student[i] = student[i-1] = 1; //나눠가짐
            else if(student[i+1]== 2) student[i] = student[i+1] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        if(student[i]>0) answer++;
    }
    return answer;
}
