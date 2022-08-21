#include <string>
#include <regex>
#include <iostream>
#include <sstream>
using namespace std; 

int main(){
	string input_string;
	cin >> input_string;

	string extracted_number = regex_replace(input_string, regex("[^0-9]"), "");

	int number = stoi(extracted_number);
	cout << number << endl;

	int divisor_count = 1;
	for(int i=1;i<number;i++){
		if(number % i == 0) divisor_count++;
	}
	cout << divisor_count << endl;
	return 0;
}