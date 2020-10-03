#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student; //학생별 체육복 수
    //순서대로 안들어 올경우..
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());

    for(int i=0;i<n;i++){
        int tmp = 1;
        if(!lost.empty() && (lost.front() == (i+1))){
            lost.erase(lost.begin());
            tmp--;
        }
        if(!reserve.empty() && (reserve.front() == (i+1))){
            reserve.erase(reserve.begin());
            tmp++;
        }
        student.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        if(student[i] == 0){
            if(i!=0 && student[i-1]>1){
                student[i-1]--;
                student[i]++;
            }
            else if(i!=(n-1)&&student[i+1]>1){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(student[i]>0) answer++;
    }
    return answer;
}

int main(){
  int n = 5;
  vector<int> lost = {2,3};
  vector<int> reserve = {3,4};
  cout << solution(n,lost,reserve);
  return 0;
}
