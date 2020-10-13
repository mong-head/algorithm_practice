#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length();
    answer.assign(len-4,'*');
    answer.append(phone_number,len-4,4);
    return answer;
}
