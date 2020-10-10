#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int solution(string dartResult);
int main()
{
  string d = "1S*2T*3S";
  int result = solution(d);
  cout << result;

  return 0;
}
int solution(string dartResult){
  int answer = 0;
  stack<int> score;
  string tmp;
  for(auto& d : dartResult){
    //d = 숫자인경우
    if(isdigit(d)) tmp+=d;
    else{
      if(!tmp.empty()){
        //d = S,D,T 인경우
        int num = stoi(tmp);
        int factor;
        tmp.clear();

        if(d=='S'||d=='T'||d=='D'){
          switch(d){
            case 'S' : factor = 1;break;
            case 'D' : factor = 2;break;
            case 'T' : factor = 3;
          }
          score.push(pow(num,factor));
        }
      }
      else{
        //* or #만난 경우
        int num1,num2;
        switch(d){
          case '*':
            num1 = score.top()*2;
            score.pop();
            if(!score.empty()){
              num2 = score.top()*2;
              score.pop();
              score.push(num2);
            }
            score.push(num1);
            break;
          case '#':
            num1 = score.top()*(-1);
            score.pop();
            score.push(num1);
            break;
        }
      }
    }
  }
  int sc_size = score.size();
  for(int i=0;i<sc_size;i++){
    answer += score.top();
    score.pop();
  }
  return answer;
}
