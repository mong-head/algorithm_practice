#include <string>
#include <vector>

using namespace std;

vector<int> how_to_solve(vector<int>& parse, int answer_size)
{
    vector<int> result;
    int parse_size = parse.size();
    int j=0;
    for(int i=0;i<answer_size;i++){
        result.push_back(parse[j++]);
        if(j>=parse_size) j=0;
    }
    return result;
}

int compare_with_answers(vector<int>& ans, vector<int>& sol)
{
    //ans : 실제 답, sol : 수포자 답
    int iter_size = ans.size();
    int result = 0; //맞은 답 개수
    for(int i=0;i<iter_size;i++){
        if(ans[i] == sol[i]) result++;
    }
    return result;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    //수포자 1,2,3 답 sequence
    vector<vector<int>> parse = {{1,2,3,4,5},
                                 {2,1,2,3,2,4,2,5},
                                 {3,3,1,1,2,2,4,4,5,5}};
    vector<vector<int>> solve;
    int answers_size = answers.size();
    for(int i=0;i<3;i++){
        solve.push_back(how_to_solve(parse[i],answers_size));
    }

    //수포자 답 맞은 개수
    int correct[3];
    for(int i=0;i<3;i++){
        correct[i] = compare_with_answers(answers,solve[i]);
    }

    //수포자 정답 개수 비교
    int max_num = max(max(correct[0],correct[1]),correct[2]);
    for(int i=0;i<3;i++){
        if(max_num == correct[i]) answer.push_back(i+1);
    }

    return answer;
}
