#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int num_size = numbers.size();

    set<int> for_answer;
    for(int i=0;i<num_size-1;i++)
    {
        for(int j=i+1;j<num_size;j++)
            for_answer.insert(numbers[i]+numbers[j]);
    }
    answer.assign(for_answer.begin(),for_answer.end());
    return answer;
}
