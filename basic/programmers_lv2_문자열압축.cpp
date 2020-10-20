#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int iter = s.length()/2;
    int len = s.length();
    for(int i=1;i<=iter;i++){
        string tmp1,tmp2;
        int count=-1;
        tmp1.assign(s,0,i);
        string compressed;
        for(int j=0;j<=len;j += i){
            tmp2.assign(s,j,i);
            count++;
            if(tmp1 != tmp2){
              if(count>1){compressed += to_string(count);}
                compressed += tmp1;
                count =0;
                tmp1 = tmp2;
            }
        }
        if(count>1){compressed += to_string(count);}
        compressed += tmp1;
        //cout << compressed <<endl;
        int tmp_answer = compressed.length();
        if(answer>tmp_answer)
            answer = tmp_answer;
    }
    return answer;
}

int main()
{
  string s = "xababcdcdababcdcd";
  cout << solution(s);
}
