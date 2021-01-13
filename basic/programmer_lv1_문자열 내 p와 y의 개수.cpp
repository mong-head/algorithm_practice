#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int pair = 0;

    for(auto& c : s){
        if(c=='p'||c=='P') pair++;
        else if(c=='y'||c=='Y') pair--;
    }
    if(!pair) answer = true;

    return answer;
}
