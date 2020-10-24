/*
<주문표 변환하기>
문제설명 : 문자열 압축한 것을 다시 풀어내기
Ex)
3R(GB) : RRRGB
R3(GB) : RGBGBGB
B3(2R(GB)) : BRRGBRRGBRRGB

--> 스택으로 풀어야함...............
근데 처음에 스택필요없을지 알고 스택으로 안 품........
ㅠㅠㅠㅠ
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void solution(int numOfOrder, string *orderArr) {
	vector<string> orders;
  for(int i=0;i<numOfOrder;i++){
		string order;
		int strlen_ = orderArr[i].length();
		int num=1;
		string for_num = "";
		string for_str = "";
		int flag = 0;
		for(int j=0;j<strlen_;j++){
			//cout << order<<endl;
			if(isdigit(orderArr[i][j])){
				for_num += orderArr[i][j];
			}
			else{
				if(for_num != ""){
					num = stoi(for_num);
					//cout <<num;
					for_num = "";
				}

				if(orderArr[i][j] == '('){
					flag++;
				}
				else if(orderArr[i][j] == ')'){
					for(int k=0;k<num;k++){
						order += for_str;
					}
					num = 1;
					flag--;
				}
				else{
					if(flag){
						for_str += orderArr[i][j];
					}
					if(num && flag==0){
						for(int k=0;k<num;k++){
						order += orderArr[i][j];
						}
					}
				}
			}
		}

		orders.push_back(order);
	}
	for(auto& order : orders){
		cout << order <<endl;
	}
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
