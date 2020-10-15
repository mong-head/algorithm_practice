#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    //* = 9, 0 = 10, # = 11
    int loc_r = 11;
    int loc_l = 9;

    for(auto& n : numbers){
        n -= 1;
        switch(n){
            case 0:
            case 3:
            case 6: answer += "L"; loc_l = n; break;
            case 2:
            case 5:
            case 8: answer += "R"; loc_r = n; break;
            case -1: n = 10;
            case 1:
            case 4:
            case 7:
                int dis_r = abs(loc_r/3-n/3)+abs(loc_r%3 - n%3);
                int dis_l = abs(loc_l/3-n/3)+abs(loc_l%3 - n%3);
                if(dis_r < dis_l){
                    loc_r = n;
                    answer += "R";
                }
                else if(dis_r > dis_l){
                    loc_l = n;
                    answer += "L";
                }
                else{
                    if(hand=="right"){
                        loc_r = n;
                        answer += "R";
                    }else if(hand=="left"){
                        loc_l = n;
                        answer += "L";
                    }
                }
        }
    }
    return answer;
}
