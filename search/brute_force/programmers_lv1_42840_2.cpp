#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    //수포자 1,2,3 답 sequence
    vector<vector<int>> parse = {{1,2,3,4,5},
                                 {2,1,2,3,2,4,2,5},
                                 {3,3,1,1,2,2,4,4,5,5}};

    vector<int> correct = {0,0,0}; //답 맞은 개수
    int answers_size = answers.size();
    for(int i=0;i<3;i++){
        int parse_size = parse[i].size();
        for(int j=0;j<answers_size;j++){
            if(answers[j] == parse[i][j%parse_size])correct[i]++;
        }
    }
    //수포자 정답 개수 비교
    int max_num = *max_element(correct.begin(),correct.end());
    for(int i=0;i<3;i++){
        if(max_num == correct[i]) answer.push_back(i+1);
    }

    return answer;
}
