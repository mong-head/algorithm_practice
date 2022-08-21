#include <string>
#include <regex>
#include <iostream>
#include <stack>
using namespace std; 

int main(){
	string input_str;
	cin >> input_str;

	stack<int> s;
	s.push(-1);
	
	for(int i=0;i<input_str.size();i++){
		if(input_str[i] == '('){
			s.push(1);
		} else if(input_str[i] == ')'){
			if(s.top()==-1){
				cout << "NO" << endl;
				return 0;
			}
			s.pop();
		}
	}
	if(s.top() == -1){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}