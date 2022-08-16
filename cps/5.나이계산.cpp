#include <string>
#include <iostream>
#include <sstream>
using namespace std; 

int main(){
	string identity_number;
	cin >> identity_number;
	int position = identity_number.find('-');

	int birth_year = stoi(identity_number.substr(0,2));
	int back_first_number = stoi(identity_number.substr(position+1).substr(0,1));

	string gender;
	if(back_first_number == 1){
		gender = "M";
		birth_year += 1900;
	} else if(back_first_number == 2){
		gender = "W";
		birth_year += 1900;
	} else if(back_first_number == 3){
		gender = "M";
		birth_year += 2000;
	} else if(back_first_number == 4){
		gender = "W";
		birth_year += 2000;
	}
	cout << 2019 - birth_year + 1 << " " << gender << endl;
	return 0;
}