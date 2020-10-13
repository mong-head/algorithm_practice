#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int size = arr1.size();
    for(int i=0;i<size;i++){
        string map = "";
        int original = arr1[i]|arr2[i];
        for(int j=pow(2,n-1);j>0;j/=2){
            if(original/j) map += "#";
            else map += " ";
            original %= j;
        }
        answer.push_back(map);
    }

    return answer;
}
