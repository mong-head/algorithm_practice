#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std; 

int main(){
	char str1[200];
	char str2[200];
	cin >> str1 >> str2;

	int str1_length = 0;
	int str2_length = 0;
	for(int i=0;i<200;i++){
		if(str1[i] == '\0'){
			str1_length = i;
			break;
		}
	}
	for(int i=0;i<200;i++){
		if(str2[i] == '\0'){
			str2_length = i;
			break;
		}
	}
	bool result = false;
	sort(str1, str1+str1_length);
	sort(str2, str2+str2_length);
	if(string(str1) == string(str2)) result = true;

	string result_str = result ? "YES" : "NO";
	cout << result_str;
}