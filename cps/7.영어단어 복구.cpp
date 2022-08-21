#include <string>
#include <regex>
#include <iostream>
#include <sstream>
using namespace std; 

int main(){
	string virus_string;
	getline(cin,virus_string);
	
	// 공백문자 제거 
	virus_string.erase(remove(virus_string.begin(), virus_string.end(), ' '), virus_string.end());

	// 대문자 -> 소문자
	for(int i=0;i<virus_string.size();i++){
		if('A' <= virus_string[i] && virus_string[i] <= 'Z'){
			virus_string[i] -= 'A' - 'a';
		}
	}
	cout << virus_string << endl;
	return 0;
}